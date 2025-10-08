datatype 'b T = F of ('b T -> 'b);

fn x => (
    x (F x)
);

fn f => (
    fn x =>
        F (x (F x))
);

val Y =
    fn f => (
        fn x =>
            f(x (F x))
    )(
        fn (F x) =>
            f(x (F x))
    )
;

val fact_closed =
    fn f =>
        fn n =>
            if
                n = 0
            then
                1
            else
                n * f (n - 1)
;

datatype 'b T = F of ('b T -> 'b);

val Z =
    fn f => (
        fn x =>
            f (fn v =>
                (x (F x)) v
            )
    )(
        fn (F x) =>
            f (fn v =>
                (x (F x)) v
            )
    )
;

val fact_closed =
    fn f =>
        fn n =>
            if
                n = 0
            then
                1
            else
                n * f (n - 1)
;

val fact = Z fact_closed;

fact 5;