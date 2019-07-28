class HelloWorld {


    private var pvalue = 0
    def increment(): Unit = {pvalue += 1}
    def current(): Int = {pvalue}
    def value=pvalue
    def value_=(newValue: Int) {
        if (newValue > 0) pvalue=newValue
    }
}

object Run {
    def main(args: Array[String]) {
    
        var myHelloWorld = new HelloWorld
        for (i <- 0 to 5) {
            myHelloWorld.increment
            println(myHelloWorld.current)
            
        }
        myHelloWorld.value = 3
        println(myHelloWorld.value)

    }

}
