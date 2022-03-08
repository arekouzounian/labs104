#include <iostream>
#include <map>
#include "Schedule.h"

using namespace std;

Schedule::Schedule(string name)
{
    mName = name;
}

bool Schedule::dropCourse(std::string name)
{
    // TO DO: if the course was not already in the map, return false
    // otherwise, remove it from the map and return true!
    for(map<string, Course*>::iterator it = courseMap.begin(); it != courseMap.end(); ++it) {
        if( it->first == name ) {
            courseMap.erase(name);
            return true;
        }
    }
    return false;
}

bool Schedule::addCourse(Course* c)
{
    // TO DO: if the course was already in the map, return false
    // otherwise, add it to the map and return true!
    for(map<string, Course*>::iterator it = courseMap.begin(); it != courseMap.end(); ++it) {
        if( it->second == c) {
            return false;
        }
    }

    courseMap.insert(make_pair(c->getCourseName(), c));
    return true;
}

void Schedule::printAllAssignments()
{
    // TO DO: print out the name of each course, followed by the set of assignments.
    // for each assignment, display its name, its type (essay vs hw vs exam), and whether or not it was completed.
    // formatting is up to you, but make sure it's easy to read!
    map<string, Course*>::iterator it; 
    for(it = courseMap.begin(); it != courseMap.end(); ++it) {
        Course* currCourse = it->second;
        cout << "Course Name: " << it->first << endl;
        cout << "Assignments: " << endl;
        set<Assignment*>::iterator as;
        set<Assignment*> st = currCourse->getAssignmentSet();
        for(as = st.begin(); as != st.end(); ++as) {
            cout << "\tName: " << (*as)->getName() << "; Type: " << (*as)->getType() << endl;
        }
    }
}

std::map<std::string, Course*> Schedule::getCourses()
{
    return courseMap;
}