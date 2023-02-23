/// T.C: O(N) Here, N = number of nodes
/// M.C: O(N)

/*
// Definition for Employee.
class Employee {
public:
    int id;
    int importance;
    vector<int> subordinates;
};
*/

class Solution {
private:
    unordered_map <int, Employee*> id_employee;
    int DFS(int u, vector<Employee*> employees){
        int subtreeSum = id_employee[u] -> importance;
        for(auto v: id_employee[u] -> subordinates)
            subtreeSum += DFS(v, employees);
        return subtreeSum;
    }
public:
    int getImportance(vector<Employee*> employees, int id) {
        for(auto emp: employees) id_employee[emp -> id] = emp;
        return DFS(id, employees);
    }
};
