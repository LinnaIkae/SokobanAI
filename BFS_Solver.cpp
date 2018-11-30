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
    fringe.clear();
    this->fringe.push_back(current);


    while (true) {
        //        std::cout << "Fringe,  size: " << this->fringe.size() << std::endl;
        //        for (auto nnn : this->fringe) {
        //            std::cout << "Node: " << nnn.agent.x << nnn.agent.y << std::endl;
        //            std::cout << "box[0]: " << nnn.boxes[0].x << nnn.boxes[0].y << "\n"
        //                    << std::endl;
        //        }

        if (this->fringe.empty()) {
            std::cout << "Failed to find solution" << std::endl;
            return false;
        }

        const Node& temp = this->fringe.front();
        Node current2(temp);

        if (goalCheck(current2)) {
            for (auto n : retracePath(&current2)) {
                std::cout << "node on the path: " << (*n).agent.x << (*n).agent.y << std::endl;
            }

            return true;

        }
        //check if not in closed
        if (std::find(closed.begin(), closed.end(), current2) == closed.end()) {
            closed.push_back(current2);
            const std::vector<Node>::iterator fringe_it = std::find(
                    fringe.begin(), fringe.end(), current2);

            fringe.erase(fringe_it);

            std::vector<Node> children = this->expandEdges(current2);

            fringe.insert(fringe.end(), children.begin(), children.end());

        } else {
            std::vector<Node>::iterator fringe_it = std::find(fringe.begin(),
                    fringe.end(), current2);

            fringe.erase(fringe_it);
        }

    }
}
