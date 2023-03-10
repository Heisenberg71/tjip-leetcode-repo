// T.C: O(number_of_visited_cells)
// M.C: O(number_of_visited_cells)


/**
 * // This is the robot's control interface.
 * // You should not implement it, or speculate about its implementation
 * class Robot {
 *   public:
 *     // Returns true if the cell in front is open and robot moves into the cell.
 *     // Returns false if the cell in front is blocked and robot stays in the current cell.
 *     bool move();
 *
 *     // Robot will stay in the same cell after calling turnLeft/turnRight.
 *     // Each turn will be 90 degrees.
 *     void turnLeft();
 *     void turnRight();
 *
 *     // Clean the current cell.
 *     void clean();
 * };
 */

class Solution {
private:
constexpr static int dir[] = {0, 1, 0, -1, 0}; // clock-wise rotation
// 0 -> right
// 1 -> down
// 2 -> left
// 3 -> up
void goback(Robot& robot){
    robot.turnRight(); robot.turnRight();
    robot.move();
    robot.turnRight(); robot.turnRight();
}
void dfs(Robot& robot, int row, int col, map< pair<int, int>, bool >& visit, int d){
    robot.clean();
    visit[{row, col}] = true;
    for(int i = 0; i < 4; i++){
        int newDir = (i + d) %4;
        int newRow = row + dir[newDir], newCol = col + dir[newDir + 1];
        if(!visit.count({newRow, newCol}) && robot.move() ){
            dfs(robot, newRow, newCol, visit, newDir);
        }
        robot.turnRight();
    }
    goback(robot);
}
public:
    void cleanRoom(Robot& robot) {
        map< pair<int, int>, bool > visit;
        dfs(robot, 0, 0, visit, 3);
    }
};
