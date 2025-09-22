def triple(x: Int): Int = x * 3

val tripleCopy: (Int) => Int = triple

println(tripleCopy(5))