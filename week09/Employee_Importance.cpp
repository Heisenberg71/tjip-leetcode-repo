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
    int DFS(int u, vector<Employee*> employees, unordered_map <int, Employee*>& id_employee){
        int subtreeSum = id_employee[u] -> importance;
        for(auto& v: id_employee[u] -> subordinates)
            subtreeSum += DFS(v, employees, id_employee);
        return subtreeSum;
    }
public:
    int getImportance(vector<Employee*> employees, int id){
        unordered_map <int, Employee*> id_employee;
        for(auto& emp: employees) id_employee[emp -> id] = emp;
        return DFS(id, employees, id_employee);
    }
};
