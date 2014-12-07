stack_constant_min
==================
Simply list implementation of min stack showing it's operations.  Internal data is hard - coded to ints
Operations Runtime:
min:  O(1)
push: O(1)
pop:  O(1)

MinStack ms;
ms.push(1);        min: 1   1 

ms.push(2);        min: 1   2 -> 1

ms.push(0);        min: 0   0 -> 2 -> 1

ms.pop();          min: 1   2 -> 1

ms.push(5);        min: 1   5 -> 2 -> 1

s.push(1);         min: 1   1 -> 5 -> 2 -> 1

ms.push(0);        min: 0   0 -> 1 -> 5 -> 2 -> 1

ms.pop();          min: 1   1 -> 5 -> 2 -> 1

ms.pop();          min: 1   5 -> 2 -> 1
