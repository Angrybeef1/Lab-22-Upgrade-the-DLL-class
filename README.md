What to submit: your Github repository URL. Commit and push your code every ten minutes when coding this assignment.

Use the demo code for doubly-linked lists that we studied in this module: 210-dll-demo-2.cppDownload 210-dll-demo-2.cpp

Your task is to upgrade the class. We want to add a few things here and there that may make the class more useful or functional to whoever is going to use it at our company.

Here are the requirements:

Create a method delete_pos() that will delete a node, not by its value, but by position. The method should also cover the case where we want to delete the head or tail node.
Create a method pop_front(), that will delete the head node.
Create a method pop_back() that will delete the tail node.
Update the current delete() method to a better name, delete_val(). Keep the functionality in the method that will still delete the head node, even though the new pop_front() method will also do that. This is fine to code both, for the purposes of class completeness.
Write a driver that fully exercises these changes made to the class.
