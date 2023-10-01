### Assignment 1: A review of pointers and memory

_*Estimated Time*_: 2 hours

### Instructions

### Part 1

<----------
_*Instructions*_: Create a new document in this directory called `assignment1-solutions.md` and bullet your solutions for the questions there. At the top of the document, please write your name and the date you started the assignment.
<----------

- What’s the difference between a null pointer and a void pointer. What happens when you dereference a null pointer? What happens if you dereference a void pointer? Explain what each error means.
- Every program runs in the context of a process. This process is allocated some amount of memory called a segment. What happens if you try to access memory outside of this segment? What is the error called?
- Are most modern architectures bit addressable or byte addressable? What is the difference?
- Assume a chunk of memory is allocated by the malloc function. Where is the memory allocated? Is there a limit to how much memory can be allocated? If so, what is the limit? (The last two parts of this question are tricky and I will accept either answer with a correct explanation. Please watch: [What if I try to malloc WAY too much memory](https://youtu.be/Fq9chEBQMFE?si=-wpfSVouxjTB2Pz4), which is only 4 minutes long, to better understand this question).
- Assume a chunk of memory is allocated by the malloc function and a void pointer is returned which points to this memory. What happens if I try to dereference that pointer? How could I cast it to another pointer type? What if I dereferenced the result of that cast?
- What happens if I add 1 to a void pointer? What happens if I add 1 to an int pointer? What happens if I add 1 to a double pointer? What is a generalized formula for this addition or subtraction process?
- Assume a chunk of memory is allocated by the malloc function and a void pointer is returned which points to this memory. What if I want to interpret bits 7-10 as an integer? How could I do this?
- How can I resize a chunk of memory to be smaller or larger? (The answer is a standard library function). What is returned by the library function? Is the chunk of memory resized in place?

### Part 2

<----------
_*Instructions*_: Watch and follow along with the following three videos:

- [Understanding and implementing a Linked List in C and Java](https://www.youtube.com/watch?v=VOpjAHCee7c)
- [Doubly Linked List (in C)](https://youtu.be/KFbm6lkMhgw?si=AmWBN5FbRhxX8851)
- [Understanding and implementing a Hash Table (in C)](https://www.youtube.com/watch?v=2Ti5yvumFTU)

For each of these videos, I want you to following along and write the code shown in the videos. Comment lines you think are important. Create a new directory called, for example `video1`, and place your code there. In each of these directories, place a file called `CMakeLists.txt` in the root with the following contents:

```CMake
cmake_minimum_required(VERSION 3.23)
project(PROJECT_NAME CXX)
set(CMAKE_C_STANDARD 23)
add_executable(PROJECT_NAME FILES)
```

Please replace `PROJECT_NAME` with `video1`, `video2`, etc. Replace `FILES` with all files that are part of your project. For example, if you have the files `main.c`, `common.h`, and `common.c`, you would place all of them (separated by spaces) where `FILES` is.

<----------

Once you're done, make a PR and I'll request corrections or merge your branch if you've done it all correctly!

I hope you have fun!
