# CPP Module 05 - Exceptions

This is an exercise to learn about [exceptions](https://en.wikipedia.org/wiki/Exception_handling) in the C++ Programming Language, as part of the [42 Core Curriculum](https://en.wikipedia.org/wiki/42_(school)).

## Overview
Throughout this module, we are modeling a governmental administration,
where bureaucrats and interns work together to create and sign forms.
Any invalid actions are dealt and handled through the use of exceptions.

### ex00
Implement a **Bureaucrat** class with 
- a constant name
- a grade ranging from 1 to 150, with 1 being the highest grade and 150 being the lowest
- getters for both member variables
- member functions to increment and decrement the grade
- an << operator overload to print its attributes

Any attempts to instantiate a **Bureaucrat** with an invalid grade will cause a GradeTooHigh or GradeTooLow exception to be thrown.

### ex01
Implement a **Form** class with
- a constant name
- a boolean indicating whether it is signed
- a constant grade required to be signed
- a constant grade required to be executed
- getters for all member variables
- a member function taking in a Bureaucrat to sign it
- an << operator overload to print its attributes

All member variables are privated and encapsulated.
Attempts to instantiate a **Form** with an invalid grade causes a GradeTooHigh or GradeTooLow exception, just as with a **Bureaucrat**.

### ex02
Implement concrete classes that derive from the now abstract **Form**.
- A **ShrubberyCreationForm** with grade 145 required for signing and grade 137 required for executing
	- when executed, creates a \<target\>_shrubbery file in the working directory, drawing an ASCII        tree inside it
- A **RobotomyRequestForm** with grade 72 required for signing and grade 45 required for executing
	- when executed, makes a drilling noise, successfully robotomizing the \<target\> 50% of the time
- A **PresidentialPardonForm** with grade 25 required for signing and grade 5 required for executing
	- when executed, informs that \<target\> has been pardoned by Zaphod Beeblebrox

Each concrete form takes in a *target* in their constructor.

Each concrete form overrides an execute() function from the abstract **Form** class, requiring a Bureaucrat to execute the form's actions, if the form was signed and the Bureaucrat has the required grade to execute it.

Any invalid operations done to a **Form** will throw an appropriate exception.

### ex03
Implement an **Intern** class with
- a member function taking in a name of a **Form**, and the name of the target.

If the **Form** does not exist, print an explicit error message. The intern's only job is to create a **Form** and assign it a target. 

> [!WARNING]
> Avoid if/else if/else solutions.

### Takeaways
This is my first real introduction to the use of exceptions for handling errors in a program.

There was once in C where I was deep into the [function call stack](https://en.wikipedia.org/wiki/Call_stack) and I had to keep returning error codes through multiple functions because we weren't allowed to exit() the program, and I recall this being annoying and even questioning whether there was no other way.

I've come to understand that exceptions can be useful in situations where you lack the context to properly handle an error. For example, library code intended to be used by others shouldn't be terminating their program, but rather return useful exceptions to indicate the error that happened to the user. Instead of painstakingly returning and propagating error codes up through the call stack, we can throw an exception to have the runtime unwind the stack for us until it is caught. It lets you separate the "logic" from the "error handling", instead of having them all congregated in one spot.

Yet, this seems to be a pretty controversial topic when it comes to "should we use exceptions in our code?" People argue that it obfuscates code as it breaks the normal control flow, and I've personally had situations where bugs were hidden as they were part of the exceptions I didn't intend to catch.

I think the lesson here is that you should type your exceptions properly, and limit what you're catching as much as possible (unless catching all exceptions is intentionally), so that errors can be properly reported. For now, I adopt the philosophy that "if I can't handle the error locally, throw an exception instead of returning an error code", and by "locally" I mean that it can't be handled in the function itself or by simply returning an error code. Despite the name, I don't think exceptions should be reserved for "exceptional situations", because, what's truly exceptional is kinda subjective, right? Is failing to open a file exceptional? Is failing to parse an integer exceptional? Ultimately I think it should all come down to the context of the error being handled.
