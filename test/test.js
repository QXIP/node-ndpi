var bindings = require('../')
var number = 33;

const assert = require("assert");

assert(bindings, "The expected module is undefined");

function testBasic()
{
    assert(bindings.testdouble, "The expected method is not defined");
    assert.strictEqual(bindings.testdouble(33), 66, "Unexpected value returned");
}

assert.doesNotThrow(testBasic, undefined, "testBasic threw an expection");

console.log("Tests passed- everything looks OK!");
