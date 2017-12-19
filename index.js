var m = require('./')

console.time('allocateBufferAndReturn')
for (var i = 0; i < 10; i++) {
  var buf = m.allocateBufferAndReturn()
}
console.timeEnd('allocateBufferAndReturn')

console.time('allocateBufferButDoNotReturn')
for (var i = 0; i < 10; i++) {
  var buf = m.allocateBufferButDoNotReturn()
}
console.timeEnd('allocateBufferButDoNotReturn')