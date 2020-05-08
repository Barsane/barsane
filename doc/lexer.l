
number: [0-9\.]+

boolean: "true" | "false"

string: ".*"

id: [a-zA-Z_][a-zA-Z0-9_]*

type: {number} | {boolean} | {string}

ids: {id} | {id} "," {ids}

declaration: {ids} : type ";"

declarations: {declaration} | {declaration} | {declarations}

factor: ["-"] {id} | ["-"] {number} | "(" {operation} ")"

term: {factor} ("*" | "/") {term} | {factor}

operation: {term} ("+" | "-") {operation} | {term}

affect: {id} "=" ({operation} | {string} | {boolean}) ";"

affects: {affect} | {affect} {affects}

expression: {operation} | {string} | {boolean}

print: "print" {expression} ";"

builtins: {print}

program: {declarations} | {affects} | {builtins}