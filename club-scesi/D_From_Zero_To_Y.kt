import java.io.BufferedReader
import java.io.InputStreamReader
import java.util.StringTokenizer

fun main() {
    val reader = BufferedReader(InputStreamReader(System.`in`))
    val tokenizer = StringTokenizer(reader.readLine())
    val T = tokenizer.nextToken().toInt()

    repeat(T) {
        val line = StringTokenizer(reader.readLine())
        xGlobal = line.nextToken().toInt()
        yGlobal = line.nextToken().toInt()
        memo = IntArray(yGlobal + 1) { -1 }
        println(dfs(0))
    }
}

private var xGlobal: Int = 0
private var yGlobal: Int = 0
private lateinit var memo: IntArray

private fun dfs(k: Int): Int {
    if (k == yGlobal) return 0
    val resCached = memo[k]
    if (resCached != -1) return resCached

    var best = Int.MAX_VALUE


    if (k + 1 <= yGlobal) {
        val steps = dfs(k + 1)
        if (steps >= 0) best = minOf(best, 1 + steps)
    }

    val rem = yGlobal - k
    var base = 1
    while (xGlobal * base <= rem) {
        val nxt = k + xGlobal * base
        val steps = dfs(nxt)
        if (steps >= 0) best = minOf(best, 1 + steps)
        base *= 10
    }

    memo[k] = if (best == Int.MAX_VALUE) -1 else best
    return memo[k]
}
