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
		cout << endl;
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
			numStudents--;
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
			numStudents--;
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
	void StudentList::insertStudent(Student s, int index)
	{
		if (index > numStudents)
		{
			cout << "Index outside list range, adding to bak of list" << endl;
			addBack(s);
		}
		else if (index == 0)
		{
			addFront(s);
		}
		else
		{
			Node *n = new Node(s);
			Node *temp = head;

			for (int i = 0 ; i < index ; i++)
			{
				temp = temp -> next;
			}

			n -> prev = temp -> prev;
			n -> next = temp;

			temp -> prev -> next = n;

			temp -> prev = n;

			numStudents++;
		}

	}

	//find the student with the given id number and return them
	// if no student matches, print a message 
	// and create and return a dummy student object
	Student StudentList::retrieveStudent(int idNum)
	{
		Student target;

		bool real = false;
		Node *temp = head;

		for (int i = 0 ; i < numStudents ; i++ )
		{
			if (temp -> data.id == idNum)
			{
				target = temp -> data;
				real = true;
			}

			temp = temp -> next;
		}

		if (real == false)
		{
			cout << "student does not exist";


		}

		return target;
	}

	// Remove a Node with a student from the list with a given id number
	// If no student matches, print a message and do nothing
	void StudentList::removeStudentById(int idNum)
	{
		Node *temp = head;
		Node *target;
		bool real = false, front = false , back = false;

		for (int i = 0 ; i < numStudents ; i++ )
		{
			if (temp -> data.id == idNum)
			{
				target = temp;
				real = true;

				if(i == 0)
				{
					front = true;
				}

				if(i == numStudents - 1)
				{
					back = true;
				}
			}

			temp = temp -> next;
		}

		if (real == false)
		{
			cout << "student does not exist";
			return;
		}
		if (front == false && back == false)
		{
			Node *p = target -> prev;
			Node *n = target -> next;

			p -> next = n;
			n -> prev = p;

			delete target;

			numStudents--;
		}
		else if(front == true)
		{
			popFront();
		}
		else
		{
			popBack();
		}
	}

	//Change the gpa of the student with given id number to newGPA
	void StudentList::updateGPA(int idNum, float newGPA)
	{
		Node *temp = head;

		for (int i = 0 ; i < numStudents ; i++ )
		{
			if (temp -> data.id == idNum)
			{
				temp -> data.GPA = newGPA;
			}

			temp = temp -> next;
		}
	}

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
	void StudentList::mergeList(StudentList &otherList)
	{
		tail -> next = otherList.head;
		otherList.head -> prev = tail;

		tail = otherList.tail;

		numStudents = numStudents + otherList.numStudents;

		otherList.tail = nullptr;
		otherList.head = nullptr;
		otherList.numStudents = 0;
	}

	//create a StudentList of students whose gpa is at least minGPA.
	//Return this list.  The original (current) list should
	//not be modified (do not remove the students from the original list).
	StudentList StudentList::honorRoll(float minGPA)
	{
		StudentList hr;

		Node *temp = head;

		for (int i = 0 ; i < numStudents ; i++ )
		{
			if (temp -> data.GPA >= minGPA)
			{
				hr.addBack(temp->data);
			}

			temp = temp -> next;
		}

		return hr;
	}
