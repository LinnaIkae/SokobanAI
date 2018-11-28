#include "BFS_Solver.hpp"

BFS_Solver::BFS_Solver() {
};

BFS_Solver::BFS_Solver(std::vector<std::string> lines) :
Solver(lines) {
};

BFS_Solver::BFS_Solver(const BFS_Solver& orig) {
}

BFS_Solver::~BFS_Solver() {
}

bool BFS_Solver::graphSearch() {

    Node current(this->agent, this->boxes);
    fringe.push_back(current);

    while (true) {
        if (fringe.empty()) {
            std::cout << "Failed to find solution" << std::endl;
            return false;
        }
        current = fringe[0];

        if (goalCheck(current)) {
            //printSolution();
            return true;

        }
        //check if not in closed
        const Node c_current = current;
        if (std::find(closed.begin(), closed.end(), current) == closed.end()) {
            closed.push_back(current);
            std::vector<Node>::iterator fringe_it = std::find(fringe.begin(),
                    fringe.end(), current);

            fringe.erase(fringe_it);
            std::vector<Node> children = expandEdges(current);
            fringe.insert(fringe.end(), children.begin(), children.end());

        } else {
            std::vector<Node>::iterator fringe_it = std::find(fringe.begin(),
                    fringe.end(), current);

            fringe.erase(fringe_it);
        }

    }
}
