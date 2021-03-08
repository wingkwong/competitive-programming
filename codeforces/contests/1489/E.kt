import java.io.PrintWriter
import java.util.*
import kotlin.math.min
 
@JvmField val INPUT = System.`in`
@JvmField val OUTPUT = System.out
 
@JvmField val _reader = INPUT.bufferedReader()
fun readLine(): String? = _reader.readLine()
fun readLn() = _reader.readLine()!!
@JvmField var _tokenizer: StringTokenizer = StringTokenizer("")
fun read(): String {
    while (_tokenizer.hasMoreTokens().not()) _tokenizer = StringTokenizer(_reader.readLine() ?: return "", " ")
    return _tokenizer.nextToken()
}
fun readInt() = read().toInt()
fun readDouble() = read().toDouble()
fun readLong() = read().toLong()
fun readStrings(n: Int) = List(n) { read() }
fun readLines(n: Int) = List(n) { readLn() }
fun readInts(n: Int) = List(n) { read().toInt() }
fun readIntArray(n: Int) = IntArray(n) { read().toInt() }
fun readDoubles(n: Int) = List(n) { read().toDouble() }
fun readDoubleArray(n: Int) = DoubleArray(n) { read().toDouble() }
fun readLongs(n: Int) = List(n) { read().toLong() }
fun readLongArray(n: Int) = LongArray(n) { read().toLong() }
 
@JvmField val _writer = PrintWriter(OUTPUT, false)
inline fun output(block: PrintWriter.() -> Unit) { _writer.apply(block).flush() }
 
fun main(args: Array<String>) {
    var N = readInt()
    var (l, r) = listOf(0, 1)
    var pos = mutableMapOf<Int, Int>()
    for(i in 0 until N) {
        var line = readLine()!!
        var type = line[0]
        var id = line.split(" ")[1].toInt()
        if(type == 'L') {
            pos[id] = l--
        } else if(type == 'R') {
            pos[id] = r++
        } else {
            var k = pos[id]!!
            println(min(k - l, r - k) - 1)
        }
    }
}