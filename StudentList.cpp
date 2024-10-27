	#include "StudentList.h"

	// Define a constructor to initialize the list. The list starts with no Students
    StudentList::StudentList()
	{
		head = nullptr;
		tail = nullptr;
		numStudents = 0;
	}

	// return the number of students currently in the list
	int StudentList::listSize()
	{
		return numStudents;
	}

	//add a Node with a student to the front (head) of the list.
	void StudentList::addFront(Student s)
	{
		if (numStudents == 0)
		{
			Node *h = new Node(s);
			head = h;
			tail = h;
			numStudents++;
		}
		else if (numStudents == 1)
		{
			Node *h = new Node(s);
			head = h;
			head -> next = tail;
			tail -> prev = head;
			numStudents++;
		}
		else
		{
			Node *h = new Node(s);
			head -> prev = h;
			h -> next = head;
			head = h;
			numStudents++;
		}
	
	}

	//add a Node with a student to the back (tail) of the list.
	void StudentList::addBack(Student s)
	{
		if (numStudents == 0)
		{
			Node *t = new Node(s);
			tail = t;
			head = t;
			numStudents++;
		}
		else if (numStudents == 1)
		{
			Node *t = new Node(s);
			tail = t;
			head -> next = tail;
			tail -> prev = head;
			numStudents++;
		}
		else
		{
			Node *t = new Node(s);
			tail -> next = t;
			t -> prev = tail;
			tail = t;
			numStudents++;
		}

	}

	//Print out the names of each student in the list.
	void StudentList::printList()
	{
		Node *temp = head;

		for (int i = 1 ; i <= numStudents ; i++)
		{
			cout << temp -> data.name << " ";

			temp = temp -> next;
		}
	}

	// Remove the Node with the student at the back (tail) of the list
	// should not fail if list is empty! Print an error message if this occurs
	// Don't forget that your head and tail pointers will be null pointers if the list is empty
	void StudentList::popBack()
	{
		if (numStudents != 0)
		{
			Node *temp = tail;
			tail = tail -> prev;
			delete temp;
		}
		else
		{
			cout << "ERROR list empty";
		}
	}

	// Remove the Node with the student at the front (head) of the list
	// should not fail if list is empty! Print an error message if this occurs
	// Don't forget that your head and tail pointers will be null pointers if the list is empty
	void StudentList::popFront()
	{
		if (numStudents != 0)
		{
			Node *temp = head;
			head = head -> next;
			delete temp;
		}
		else
		{
			cout << "ERROR list empty";
		}
	}

	//insert a student at the position "index".
	// for this list, count head as index 0
	// if index is outside of current list range, 
	// print a message and insert the student at the back of the list
	// the previous Node at your target index should be moved forward. "For exampe, Node with student at index i, becomes index i+1" 
	// Remember that you already have methods that can add students to the front or back of list if needed! Don't repeat this code.
	void StudentList::insertStudent(Student s, int index) {}

	//find the student with the given id number and return them
	// if no student matches, print a message 
	// and create and return a dummy student object
	Student StudentList::retrieveStudent(int idNum) {
		Student fixthis;
		return fixthis;
	}

	// Remove a Node with a student from the list with a given id number
	// If no student matches, print a message and do nothing
	void StudentList::removeStudentById(int idNum) {}

	//Change the gpa of the student with given id number to newGPA
	void StudentList::updateGPA(int idNum, float newGPA) {}

	//Add all students from otherList to this list.
	//otherlist should be empty after this operation.
	/*
	For example, if the list has 3 students:
	s1 <-> s2 <-> s3
	and otherList has 2 students
	s4 <-> s5
	then after mergeList the currently list should have all 5 students
	s1 <-> s2 <-> s3 <-> s4 <-> s5
	and otherList should be empty and have zero students.
	*/
	void StudentList::mergeList(StudentList &otherList) {}

	//create a StudentList of students whose gpa is at least minGPA.
	//Return this list.  The original (current) list should
	//not be modified (do not remove the students from the original list).
	StudentList StudentList::honorRoll(float minGPA) {
		StudentList fixthis;
		return fixthis;
	}
