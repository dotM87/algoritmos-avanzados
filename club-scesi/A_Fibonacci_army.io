n := File standardInput readLine asNumber
fibo := method(n,
    if(n <= 1,
        1,
        self fibo(n - 1) + self fibo(n - 2)
    )
)
write(fibo(n))