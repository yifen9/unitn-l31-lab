(*Improve the previous exercise by printing an error message and raising an exception when the input is bad*)

exception badInput;

fun trap1(a,b,n,F) =
    if
        n<=0 orelse b-a<=0.0
    then
        raise badInput
    else
        let
            val delta = (b-a)/real(n);
            
            fun trap1(x,0) = 0.0
            | trap1(x,i) = delta*(F(x)+F(x+delta))/2.0 + trap1(x+delta,i-1)
        in
            trap1(a,n)
        end
;

fun trap(a,b,n,F) = trap1(a,b,n,F) handle badInput => (
    print ("Bad Input\n");
    
    0.0
);