# fiestaSort.c
### ridiculous sorting algorithm lol

so a few weeks ago while I was bored I saw at a [golf](https://en.wikipedia.org/wiki/Code_golf) sorting question on [the codegolf stackexchange](https://codegolf.stackexchange.com/)  
I can't remember the exact wording, but it more or less said "sort in the fewest number of bytes possible"  

I also think the original question had an additional given that each value only appears once in the input,  
I didn't take this into account and just wrote it generally tho  

**but** I instead added my own restriction that I'd use C and not use a single `for`/`do`/`while`/`if`  
wild right? xD

I remember some languages were able to do the original question in less than 5 *bytes* but I don't think that's possible in C lmao  
anyway, I originaly wrote this code a while back, but I wasn't using git/github much at that point, might as well upload it now

also iirc, a number of the answers I saw were [Bogosorts](https://en.wikipedia.org/wiki/Bogosort) of some form, kinda just generating each permutation  
but this one is provably [O(n<sup>2</sup>)](https://en.wikipedia.org/wiki/Time_complexity) despite having a single mysterious goto  
xD
