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
    var (N, M, K) = readInts(3)
    var A = readIntArray(N)
    var ans = 0
    var sum = K 
    var i = N - 1
    while(i >= 0) {
        if(A[i] > K) {
            i--
            continue
        }
        if(sum >= A[i]) {
            sum -= A[i]
            ans++
        } else {
            M--
            i++
            if(M <= 0) {
                break
            }
            sum = K
        }
        i--
    }
    println(ans)
}