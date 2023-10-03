Jenny Cho
10/1/2023

### Part 1

- What’s the difference between a null pointer and a void pointer. What happens when you dereference a null pointer? What happens if you dereference a void pointer? Explain what each error means.

A null pointer is a pointer to an invalid address in memory, which is usually the address 0x0 in memory. Void pointers are a type of pointers that aren't complete types. If you dereference a null pointer, you get a seg fault because you are essentially access an illegal space in memory (it's memory that doesn't belong to your process). If you dereference a void pointer, you get an incomplete error as void is an incomplete type (a type that does not have a size).

- Every program runs in the context of a process. This process is allocated some amount of memory called a segment. What happens if you try to access memory outside of this segment? What is the error called?

This causes a seg fault. You are committing an memory access violation.

- Are most modern architectures bit addressable or byte addressable? What is the difference?

Most modern architectures are byte addressable; each byte has a memory address. In a bit addressable machine, each bit has a memory address. This is the case as bit addressable machines would require 8 times as many wires as a byte addressable.

- Assume a chunk of memory is allocated by the malloc function. Where is the memory allocated? Is there a limit to how much memory can be allocated? If so, what is the limit? (The last two parts of this question are tricky and I will accept either answer with a correct explanation. Please watch: [What if I try to malloc WAY too much memory](https://youtu.be/Fq9chEBQMFE?si=-wpfSVouxjTB2Pz4), which is only 4 minutes long, to better understand this question).

Malloc function memory is allocated within a provided segment on the heap in memory for our process. The limit on how much memory can be allocated depends on the amount of RAM in your computer. Malloc will mislead you; it will give you more memory than possible.


- Assume a chunk of memory is allocated by the malloc function and a void pointer is returned which points to this memory. What happens if I try to dereference that pointer? How could I cast it to another pointer type? What if I dereferenced the result of that cast?

Dereferencing a void pointer in memory allocated by the malloc function will result in an incomplete error since it is an incomplete type. You can cast a void pointer to another pointer type using the syntax (Type)(Object), for example (int*)(x) where x is a pointer type. When dereferencing this cast type, it interprets the first n bytes of that memory as the pointer's type where n is the size of the pointer's type. For example, if given 100 bytes in memory, the first 4 bytes will be interpreted as an integer if the pointer pointing to the address is cast as an int pointer.

- What happens if I add 1 to a void pointer? What happens if I add 1 to an int pointer? What happens if I add 1 to a double pointer? What is a generalized formula for this addition or subtraction process?

When you add 1 to a void pointer, the address of the pointer incrememts by 1. If you add 1 to an int pointer, the address of the pointer increments by 4. If you add 1 to a double pointer, the address of the pointer incremements by 8. When you incrememnt a pointer, it moves forward by the amount of bytes of the underlying datatype. When you decrement a pointer, the value of the pointer's current address decreases by the amount of bytes of the underlying datatype. 

- Assume a chunk of memory is allocated by the malloc function and a void pointer is returned which points to this memory. What if I want to interpret bits 7-10 as an integer? How could I do this?

Since malloc returns a void pointer, you would need to cast it to the appropriate type. In this case, we need to cast the void pointer to an int pointer. Then, we can use bitwise operations to interpret bits 7-10 as an integer.


- How can I resize a chunk of memory to be smaller or larger? (The answer is a standard library function). What is returned by the library function? Is the chunk of memory resized in place?

You can resize a previouslly allocated block of memory using the reallic function. The chunk of memory can be resized in place (the memory block is adjusted without being moved to a different location in memory) if there is enough space in the current block to expand or shrink. Otherwise, it copies the data from the old block of memory to a new block with the adjusted size and frees the old block.