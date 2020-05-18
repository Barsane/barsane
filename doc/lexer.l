
number: [0-9\.]+

boolean: "true" | "false"

string: ".*"

id: [a-zA-Z_][a-zA-Z0-9_]*

type: "number" | "boolean" | "string"

ids: {id} | {id} "," {ids}

declaration: {ids} : type ";"

declarations: {declaration} | {declaration} | {declarations}

factor: ["-"] {id} | ["-"] {number} | "(" {operation} ")"

term: {factor} ("*" | "/") {term} | {factor}

operation: {term} ("+" | "-") {operation} | {term}

expression: {operation} | {string} | {boolean}

affect: {id} "=" {expression} ";"

affects: {affect} | {affect} {affects}

print: "print" {expression} ";"

builtins: {print}

instruction: {declarations} | {affects} | {builtins}

instructions: instruction | instruction instructions

program: {instructions}
