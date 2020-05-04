//
// Created by souls on 02/05/2020.
//

#include "StrTest.h"

void StrTest::getType_When_KeyIs() {
    map<string, StrType> keyString;
    keyString[" \t\n  \r"] = SPACE;
   keyString["1_2ap"] = ALPHANUMERIC_OR_UNDERSCORE;
    keyString["12"] = ALPHANUMERIC_OR_UNDERSCORE;
    keyString["abcz"] = ALPHANUMERIC_OR_UNDERSCORE;
    keyString["__"] = ALPHANUMERIC_OR_UNDERSCORE;
    keyString[")(+-"] = SPECIAL;
    keyString[" hello"] = UNDEFINED;
    keyString["(=/*&é\"'(-è_çà)=$ù£ù%!:jo"] = UNDEFINED;
    for (auto chars : keyString) {
        str key = str(chars.first);
        expect(chars.first + " should be expected type", chars.second == key.getType());
    }
}

void StrTest::getValue_When_KeyIs() {
    vector<string> chars = {" \t\n", "125", "ab", "£$ù:!1", "x", "true"};
    for (auto chr : chars) {
        str key(chr);
        expect(chr + " should be " + chr, key.value() == chr);
    }
}

void StrTest::strIsSpace_When_KeyIs() {
    str whitespace(" \t\n\r");
    str bad(" m");
    expect("' \\t\\n\\r' should be space", whitespace.isSpace());
    expect("' m' should not be space", !bad.isSpace());
}

void StrTest::strIsNumeric_When_KeyIs() {
    str flt("1.5");
    str badFlt(".2");
    str integer("1226");
    str bad("12m");
    str veryBad("mpo");

    expect("1.5 should be numeric", flt.isNumeric());
    expect(".2 should not be numeric", !badFlt.isNumeric());
    expect("1226 should be numeric", integer.isNumeric());
    expect("12m should not be numeric", !bad.isNumeric());
    expect("mpo should not be numeric", !veryBad.isNumeric());
}

void StrTest::strIsAlphaUnd_When_KeyIs() {
    str alpha("abcd");
    str alphaUnd1("_poole");
    str alphaUnd("x_");
    str underscore("__");
    str bad("mo12");

    expect("abcd should be alpha or underscore", alpha.isAlphaUnd());
    expect("_poole should be alpha or underscore", alphaUnd.isAlphaUnd());
    expect("x_ should be alpha or underscore", alphaUnd1.isAlphaUnd());
    expect("__ should be alpha or underscore", underscore.isAlphaUnd());
    expect("mo12 should not alpha nor underscore", !bad.isAlphaUnd());
}

void StrTest::strIsAlphaNumUnd_WHen_KeyIs() {
    str alpha("abcd");
    str alphaUnd1("_poole");
    str alphaUnd("x_");
    str underscore("__");
    str alphanum("mo12");
    str bad("mo12µ");

    expect("abcd should be alpha or underscore or numeric",
            alpha.isAlphaNumUnd());
    expect("_poole should be alpha or underscore or numeric",
            alphaUnd.isAlphaNumUnd());
    expect("x_ should be alpha or underscore or numeric",
            alphaUnd1.isAlphaNumUnd());
    expect("__ should be alpha or underscore or numeric",
            underscore.isAlphaNumUnd());
    expect("mo12 should be alpha or underscore or numeric",
            alphanum.isAlphaNumUnd());
    expect("mo12µ should not be alpha nor underscore nor numeric",
            !bad.isAlphaNumUnd());
}

void StrTest::strIsSpecial_When_KeyIs() {
    str special("!=-/");
    str badAlpha("pom-");
    str badNum("12");

    expect("><µ/- should be special", special.isSpecial());
    expect("pom- should not be special", !badAlpha.isSpecial());
    expect("12 should not be special", !badNum.isSpecial());

}

void StrTest::strIsExpression_When_KeyIs() {
    str expression("\"1517%.::lefde+-éé-(_80ç\"");
    str missRight("\"1517%.::lefde+-éé-(_80ç");
    str missLeft("1517%.::lefde+-éé-(_80ç\"");
    str miss("1517%.::lefde+-éé-(_80ç");

    expect("'\"1517%.::lefde+-éé-(_80ç\"' should be an expression",
            expression.isExpression());
    expect("'\"1517%.::lefde+-éé-(_80ç' should not be an expression",
            !missRight.isExpression());
    expect("'1517%.::lefde+-éé-(_80ç\"' should not be an expression",
            !missLeft.isExpression());
    expect("'1517%.::lefde+-éé-(_80ç' should not be an expression",
            !miss.isExpression());
}

void StrTest::run() {
    getType_When_KeyIs();
    getValue_When_KeyIs();
    strIsSpace_When_KeyIs();
    strIsNumeric_When_KeyIs();
    strIsAlphaUnd_When_KeyIs();
    strIsAlphaNumUnd_WHen_KeyIs();
    strIsSpecial_When_KeyIs();
    strIsExpression_When_KeyIs();
}