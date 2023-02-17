/*
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at https://mozilla.org/MPL/2.0/.
 */

#include <filesystem>
#include <iostream>
#include <vector>

#include "common/fileio.h"
#include "common/log.h"
#include "common/stream.h"
#include "director/chunk.h"
#include "director/dirfile.h"

using namespace Director;

int main(int argc, char *argv[]) {
	bool dumpChunks = false;
	bool dumpJSON = false;
	bool dumpScripts = false;
	std::string input;
	bool foundInput = false;
	std::string output;
	bool foundOutput = false;

	int argsUsed;
	for (argsUsed = 1; argsUsed < argc; argsUsed++) {
		std::string arg = argv[argsUsed];
		if (arg == "--dump-chunks") {
			dumpChunks = true;
		} else if (arg == "--dump-json") {
			dumpJSON = true;
		} else if (arg == "--dump-scripts") {
			dumpScripts = true;
		} else if (arg == "-v" || arg == "--verbose") {
			Common::g_verbose = true;
		} else if (!foundInput) {
			input = arg;
			foundInput = true;
		} else if (!foundOutput) {
			output = arg;
			foundOutput = true;
		} else {
			break;
		}
	}

	if (argsUsed != argc || !foundInput || !foundOutput) {
		Common::log(boost::format("Usage: %s [OPTIONS]... INPUT_FILE OUTPUT_FILE") % argv[0]);
		Common::log("  --dump-chunks\t\tDump chunk data");
		Common::log("  --dump-json\t\tDump JSONifed chunk data");
		Common::log("  --dump-scripts\tDump scripts");
		Common::log("  -v or --verbose\tVerbose logging");
		return 1;
	}

	std::vector<uint8_t> buf;
	if (!Common::readFile(input, buf)) {
		Common::warning(boost::format("Could not read %s!") % input);
		return -1;
	}

	Common::ReadStream stream(buf.data(), buf.size());
	auto dir = std::make_unique<DirectorFile>();
	if (!dir->read(&stream))
		return -1;

	if (dumpChunks) {
		dir->dumpChunks();
	}
	if (dumpJSON) {
		dir->dumpJSON();
	}
	if (dumpScripts) {
		dir->dumpScripts();
	}

	dir->config->unprotect();
	dir->restoreScriptText();
	dir->writeToFile(output);

	return 0;
}
