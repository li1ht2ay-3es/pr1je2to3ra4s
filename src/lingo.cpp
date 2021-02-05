#include "lingo.h"
#include "util.h"

namespace ProjectorRays {

/* Lingo */

std::map<uint, std::string> Lingo::opcodeNames = {
    // single-byte
    { kOpRet,               "ret" },
    { kOpPushZero,          "pushzero" },
    { kOpMul,               "mul" },
    { kOpAdd,               "div" },
    { kOpSub,               "sub" },
    { kOpDiv,               "div" },
    { kOpMod,               "mod" },
    { kOpInv,               "inv" },
    { kOpJoinStr,           "joinstr" },
    { kOpJoinPadStr,        "joinpadstr" },
    { kOpLt,                "lt" },
    { kOpLtEq,              "lteq" },
    { kOpNtEq,              "nteq" },
    { kOpEq,                "eq" },
    { kOpGt,                "gt" },
    { kOpGtEq,              "gteq" },
    { kOpAnd,               "and" },
    { kOpOr,                "or" },
    { kOpNot,               "not" },
    { kOpContainsStr,       "containsstr" },
    { kOpContains0Str,      "contains0str" },
    { kOpSplitStr,          "splitstr" },
    { kOpHiliiteStr,        "hilitestr" },
    { kOpOntoSpr,           "ontospr" },
    { kOpIntoSpr,           "intospr" },
    { kOpCastStr,           "caststr" },
    { kOpStartObj,          "startobj" },
    { kOpStopObj,           "stopobj" },
    { kOpPushList,          "pushlist" },
    { kOpPushPropList,      "pushproplist" },

    // multi-byte
    { kOpPushInt01,         "pushint01" },
    { kOpPushArgListNoRet,  "pusharglistnoret" },
    { kOpPushArgList,       "pusharglist" },
    { kOpPushCons,          "pushcons" },
    { kOpPushSymb,          "pushsymb" },
    { kOpGetGlobal,         "getglobal" },
    { kOpGetProp,           "getprop" },
    { kOpGetParam,          "getparam" },
    { kOpGetLocal,          "getlocal" },
    { kOpSetGlobal,         "setglobal" },
    { kOpSetProp,           "setprop" },
    { kOpSetParam,          "setparam" },
    { kOpSetLocal,          "setlocal" },
    { kOpJmp,               "jmp" },
    { kOpEndRepeat,         "endrepeat" },
    { kOpJmpIfZ,            "jmpifz" },
    { kOpCallLocal,         "localcall" },
    { kOpCallExt,           "extcall" },
    { kOpCallObjOld,        "oldobjcall" },
    { kOp59XX,              "op59xx" },
    { kOp5BXX,              "op5Bxx" },
    { kOpGet,               "get" },
    { kOpSet,               "set" },
    { kOpGetMovieProp,      "getmovieprop" },
    { kOpSetMovieProp,      "setmovieprop" },
    { kOpGetObjProp,        "getobjprop" },
    { kOpSetObjProp,        "setobjprop" },
    { kOpGetMovieInfo,      "getmovieinfo" },
    { kOpCallObj,           "objcall" },
    { kOpPushInt2E,         "pushint2E" }
};

std::map<uint, std::string> Lingo::binaryOpNames = {
    { kOpMul,           "*" },
    { kOpAdd,           "+" },
    { kOpSub,           "-" },
    { kOpDiv,           "/" },
    { kOpMod,           "mod" },
    { kOpJoinStr,       "&" },
    { kOpJoinPadStr,    "&&" },
    { kOpLt,            "<" },
    { kOpLtEq,          "<=" },
    { kOpNtEq,          "<>" },
    { kOpEq,            "=" },
    { kOpGt,            ">" },
    { kOpGtEq,          ">=" },
    { kOpAnd,           "and" },
    { kOpOr,            "or" },
    { kOpContainsStr,   "contains" },
    { kOpContains0Str,  "starts" }
};

std::map<uint, std::string> Lingo::moviePropertyNames00 = {
    { 0x00, "floatPrecision" },
    { 0x01, "mouseDownScript" },
    { 0x02, "mouseUpScript" },
    { 0x03, "keyDownScript" },
    { 0x04, "keyUpScript" },
    { 0x05, "timeoutScript" },
    { 0x06, "short time" },
    { 0x07, "abbr time" },
    { 0x08, "long time" },
    { 0x09, "short date" },
    { 0x0a, "abbr date" },
    { 0x0b, "long date" }
};

std::map<uint, std::string> Lingo::chunkTypeNames = {
    { kChunkChar, "char" },
    { kChunkWord, "word" },
    { kChunkItem, "item" },
    { kChunkLine, "line" }
};

std::map<uint, std::string> Lingo::menuPropertyNames = {
    { 0x01, "name" },
    { 0x02, "number of menuItems" }
};

std::map<uint, std::string> Lingo::menuItemPropertyNames = {
    { 0x01, "name" },
    { 0x02, "checkMark" },
    { 0x03, "enabled" },
    { 0x04, "script" }
};

std::map<uint, std::string> Lingo::soundPropertyNames = {
    { 0x01, "volume" }
};

std::map<uint, std::string> Lingo::spritePropertyNames = {
    { 0x01, "type" },
    { 0x02, "backColor" },
    { 0x03, "bottom" },
    { 0x04, "castNum" },
    { 0x05, "constraint" },
    { 0x06, "cursor" },
    { 0x07, "foreColor" },
    { 0x08, "height" },
    { 0x0a, "ink" },
    { 0x0b, "left" },
    { 0x0c, "lineSize" },
    { 0x0d, "locH" },
    { 0x0e, "locV" },
    { 0x0f, "movieRate" },
    { 0x10, "movieTime" },
    { 0x12, "puppet" },
    { 0x13, "right" },
    { 0x14, "startTime" },
    { 0x15, "stopTime" },
    { 0x16, "stretch" },
    { 0x17, "top" },
    { 0x18, "trails" },
    { 0x19, "visible" },
    { 0x1a, "volume" },
    { 0x1b, "width" },
    { 0x1d, "scriptNum" },
    { 0x1e, "moveableSprite" },
    { 0x20, "scoreColor" }
};

std::map<uint, std::string> Lingo::moviePropertyNames07 = {
    { 0x01, "beepOn" },
    { 0x02, "buttonStyle" },
    { 0x03, "centerStage" },
    { 0x04, "checkBoxAccess" },
    { 0x05, "checkboxType" },
    { 0x06, "colorDepth" },
    { 0x08, "exitLock" },
    { 0x09, "fixStageSize" },
    { 0x13, "timeoutLapsed" },
    { 0x17, "selEnd" },
    { 0x18, "selStart" },
    { 0x19, "soundEnabled" },
    { 0x1a, "soundLevel" },
    { 0x1b, "stageColor" },
    { 0x1d, "stillDown" },
    { 0x1e, "timeoutKeyDown" },
    { 0x1f, "timeoutLength" },
    { 0x20, "timeoutMouse" },
    { 0x21, "timeoutPlay" },
    { 0x22, "timer" }
};

std::map<uint, std::string> Lingo::moviePropertyNames08 = {
    { 0x01, "perFrameHook" },
    { 0x02, "number of castMembers" },
    { 0x03, "number of menus" }
};

std::map<uint, std::string> Lingo::castPropertyNames09 = {
    { 0x01, "name" },
    { 0x02, "text" },
    { 0x08, "picture" },
    { 0x0a, "number" },
    { 0x0b, "size" },
    { 0x11, "foreColor" },
    { 0x12, "backColor" }
};

std::map<uint, std::string> Lingo::fieldPropertyNames = {
    { 0x03, "textStyle" },
    { 0x04, "textFont" },
    { 0x05, "textHeight" },
    { 0x06, "textAlign" },
    { 0x07, "textSize" }
};

std::map<uint, std::string> Lingo::castPropertyNames0D = {
    { 0x01, "sound" }
};

std::string Lingo::getOpcodeName(uint8_t id) {
    if (id >= 0x40)
        id = 0x40 + id % 0x40;
    auto it = opcodeNames.find(id);
    if (it == opcodeNames.end()){
        char hexID[3];
        sprintf(hexID, "%02X", id);
        std::string res = "unk";
        res.append(hexID);
        return res;
    }
    return it->second;
}

std::string Lingo::getName(const std::map<uint, std::string> &nameMap, uint id) {
    auto it = nameMap.find(id);
    if (it == nameMap.end())
        return "ERROR";
    return it->second;
}

/* Datum */

int Datum::toInt() {
    switch (type) {
    case kDatumInt:
        return i;
    case kDatumFloat:
        return f;
    default:
        break;
    }
    return 0;
}

std::string Datum::toString(bool summary) {
    switch (type) {
    case kDatumVoid:
        return "VOID";
    case kDatumSymbol:
        return "#" + s;
    case kDatumString:
        return "\"" + s + "\""; // FIXME: escape
    case kDatumInt:
        return std::to_string(i);
    case kDatumFloat:
        return std::to_string(f);
    case kDatumList:
    case kDatumArgList:
    case kDatumArgListNoRet:
        {
            std::string res = "";
            if (type == kDatumList)
                res += "[";
            for (size_t i = 0; i < l.size(); i++) {
                if (i > 0)
                    res += ", ";
                res += l[i]->toString(summary);
            }
            if (type == kDatumList)
                res += "]";
            return res;
        }
    case kDatumPropList:
        {
            std::string res = "[";
            if (l.size() == 0) {
                res += ":";
            } else {
                for (size_t i = 0; i < l.size(); i += 2) {
                    if (i > 0)
                        res += ", ";
                    res += l[i]->toString(summary) + ": " + l[i + 1]->toString(summary);
                }
            }
            res += "]";
            return res;
        }
    }

    return "ERROR";
}

/* AST */

std::string AST::toString(bool summary) {
    return root->toString(summary);
}

void AST::addStatement(std::shared_ptr<Node> statement) {
    currentBlock->addChild(std::move(statement));
}

void AST::enterBlock(BlockNode *block) {
    currentBlock = block;
}

void AST::exitBlock() {
    auto parent = currentBlock->parent; // handler
    if (!parent) {
        currentBlock = nullptr;
        return;
    }

    auto grandparent = parent->parent; // block
    if (!grandparent) {
        currentBlock = nullptr;
        return;
    }

    auto newBlock = static_cast<BlockNode *>(grandparent);
    if (!newBlock) {
        currentBlock = nullptr;
        return;
    }

    currentBlock = newBlock;
}

/* Node */

std::string Node::toString(bool summary) {
    return "";
}

std::shared_ptr<Datum> Node::getValue() {
    return std::make_shared<Datum>();
}

/* ErrorNode */

std::string ErrorNode::toString(bool summary) {
    return "ERROR";
}

/* CommentNode */

std::string CommentNode::toString(bool summary) {
    return "-- " + text;
}

/* LiteralNode */

std::string LiteralNode::toString(bool summary) {
    return value->toString(summary);
}

std::shared_ptr<Datum> LiteralNode::getValue() {
    return value;
}

/* BlockNode */

std::string BlockNode::toString(bool summary) {
    std::string res = "";
    for (const auto &child : children) {
        res += indent(child->toString(summary) + "\n");
    }
    return res;
}

void BlockNode::addChild(std::shared_ptr<Node> child) {
    child->parent = this;
    children.push_back(std::move(child));
}

/* HandlerNode */

std::string HandlerNode::toString(bool summary) {
    std::string res = "on " + handler->name;
    if (handler->argumentNames.size() > 0) {
        res += " ";
        for (size_t i = 0; i < handler->argumentNames.size(); i++) {
            if (i > 0)
                res += ", ";
            res += handler->argumentNames[i];
        }
    }
    res += "\n";
    if (handler->globalNames.size() > 0) {
        res += "  global ";
        for (size_t i = 0; i < handler->globalNames.size(); i++) {
            if (i > 0)
                res += ", ";
            res += handler->globalNames[i];
        }
        res += "\n";
    }
    res += block->toString(summary);
    res += "end\n";
    return res;
}

/* ExitStmtNode */

std::string ExitStmtNode::toString(bool summary) {
    return "exit";
}

/* InverseOpNode */

std::string InverseOpNode::toString(bool summary) {
    return "-" + operand->toString(summary);
}

/* NotOpNode */

std::string NotOpNode::toString(bool summary) {
    return "not " + operand->toString(summary);
}

/* BinaryOpNode */

std::string BinaryOpNode::toString(bool summary) {
    auto opString = Lingo::getName(Lingo::binaryOpNames, opcode);
    return left->toString(summary) + " " +  opString + " " + right->toString(summary);
}

/* StringSplitExprNode */

std::string StringSplitExprNode::toString(bool summary) {
    auto typeString = Lingo::getName(Lingo::chunkTypeNames, type);
    auto res = string->toString(summary) + "." + typeString + "[" + first->toString(summary);
    if (last->getValue()->toInt()) {
        res += ".." + last->toString(summary);
    }
    res += "]";
    return res;
}

/* StringHiliteStmtNode */

std::string StringHiliteStmtNode::toString(bool summary) {
    auto typeString = Lingo::getName(Lingo::chunkTypeNames, type);
    auto res = string->toString(summary) + "." + typeString + "[" + first->toString(summary);
    if (last->getValue()->toInt()) {
        res += ".." + last->toString(summary);
    }
    res += "].hilite()";
    return res;
}

/* SpriteIntersectsExprNode */

std::string SpriteIntersectsExprNode::toString(bool summary) {
    return "sprite(" + firstSprite->toString(summary) + ").intersects(" + secondSprite->toString(summary) + ")";
}

/* SpriteWithinExprNode */

std::string SpriteWithinExprNode::toString(bool summary) {
    return "sprite(" + firstSprite->toString(summary) + ").within(" + secondSprite->toString(summary) + ")";
}

/* FieldExprNode */

std::string FieldExprNode::toString(bool summary) {
    return "field(" + fieldID->toString(summary) + ")";
}

/* VarNode */

std::string VarNode::toString(bool summary) {
    return varName;
}

/* AssignmentStmtNode */

std::string AssignmentStmtNode::toString(bool summary) {
    return variable->toString(summary) + " = " + value->toString(summary);
}

/* IfStmtNode */

std::string IfStmtNode::toString(bool summary) {
    std::string res;
    switch (ifType) {
    case kIf:
        res = "if " + condition->toString(summary) + " then";
        break;
    case kIfElse:
        res = "if " + condition->toString(summary) + " then";
        break;
    case kRepeatWhile:
        res = "repeat while " + condition->toString(summary);
        break;
    }
    if (summary) {
        if (ifType == kIfElse) {
            res += " / else";
        }
    } else {
        res += "\n";
        res += block1->toString(summary);
        if (ifType == kIfElse) {
            res += "else\n" + block2->toString(summary);
        }
        if (ifType == kRepeatWhile) {
            res += "end repeat";
        } else {
            res += "end if";
        }
    }
    return res;
}

/* CallNode */

std::string CallNode::toString(bool summary) {
    return name + "(" + argList->toString(summary) + ")";
}

/* ObjCallNode */

std::string ObjCallNode::toString(bool summary) {
    return obj->toString(summary) + "." + name + "(" + argList->toString(summary) + ")";
}

/* TheExprNode */

std::string TheExprNode::toString(bool summary) {
    return "the " + prop;
}

/* LastStringChunkExprNode */

std::string LastStringChunkExprNode::toString(bool summary) {
    auto typeString = Lingo::getName(Lingo::chunkTypeNames, type);
    return "the last " + typeString + " in " + string->toString(summary);
}

/* StringChunkCountExprNode */

std::string StringChunkCountExprNode::toString(bool summary) {
    auto typeString = Lingo::getName(Lingo::chunkTypeNames, type);
    return "the number of " + typeString + " in " + string->toString(summary);
}

/* MenuPropExprNode */

std::string MenuPropExprNode::toString(bool summary) {
    auto propString = Lingo::getName(Lingo::menuPropertyNames, prop);
    return "menu(" + menuID->toString(summary) + ")." + propString;
}

/* MenuItemPropExprNode */

std::string MenuItemPropExprNode::toString(bool summary) {
    auto propString = Lingo::getName(Lingo::menuItemPropertyNames, prop);
    return "menu(" + menuID->toString(summary) + ").item(" + itemID->toString(summary) + ")." + propString;
}

/* SoundPropExprNode */

std::string SoundPropExprNode::toString(bool summary) {
    auto propString = Lingo::getName(Lingo::soundPropertyNames, prop);
    return "sound(" + soundID->toString(summary) + ")." + propString;
}

/* SpritePropExprNode */

std::string SpritePropExprNode::toString(bool summary) {
    auto propString = Lingo::getName(Lingo::spritePropertyNames, prop);
    return "sprite(" + spriteID->toString(summary) + ")." + propString;
}

/* CastPropExprNode */

std::string CastPropExprNode::toString(bool summary) {
    return "cast(" + castID->toString(summary) + ")." + prop;
}

/* FieldPropExprNode */

std::string FieldPropExprNode::toString(bool summary) {
    auto propString = Lingo::getName(Lingo::fieldPropertyNames, prop);
    return "field(" + fieldID->toString(summary) + ")." + propString;
}

/* ObjPropExprNode */

std::string ObjPropExprNode::toString(bool summary) {
    return obj->toString(summary) + "." + prop;
}

/* ExitRepeatStmtNode */

std::string ExitRepeatStmtNode::toString(bool summary) {
    return "exit repeat";
}

/* NextRepeatStmtNode */

std::string NextRepeatStmtNode::toString(bool summary) {
    return "next repeat";
}

}
