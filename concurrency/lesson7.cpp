// if you do not want to handle locks yourself in case of shared resources
// use atomic
#include<atomic>

// instead of creating normal variables/object create atomic wrapped object
static std::atomic<int> sharedVar = 0;

// after that you do not have to use locks. Atomicity of the data is maintained by the wrapper
// always check for the docs for operator and method overloads
// better used in case of primitive data types.
// user defined data-types required handware level bytes representation. (no idea what that means)