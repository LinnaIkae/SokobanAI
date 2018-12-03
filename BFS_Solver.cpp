#include "BFS_Solver.hpp"
#include "Grid.hpp"

BFS_Solver::BFS_Solver() {
};

BFS_Solver::BFS_Solver(std::vector<std::string> lines) :
Solver(lines) {
};

BFS_Solver::BFS_Solver(const BFS_Solver& orig) {
}

BFS_Solver::~BFS_Solver() {
}

bool BFS_Solver::graphSearch(Grid& g, sf::RenderWindow& window) {

    Node current(this->agent, this->boxes);
    g.draw(window, current);
    fringe.clear();
    this->fringe.push_back(current);
    std::cout << "First Node: " << std::endl;
    current.debugPrint();

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

        //eli tässä kun current muutetaan, se säilyttää saman oman osoitteen,
        //jolloin se on oman itsensä parent.

        //TODO: keksi keino miten tämä korjataan.

        current = this->fringe.front();

        g.draw(window, current);
        //std::cout << "current: " << std::endl;
        //current.debugPrint();

        if (goalCheck(current)) {
            for (auto n : retracePath(&current)) {
                std::cout << "node on the path: " << (*n).agent.x << (*n).agent.y << std::endl;
            }

            return true;

        }
        //check if not in closed
        if (std::find(closed.begin(), closed.end(), current) == closed.end()) {
            closed.push_back(current);
            const std::vector<Node>::iterator fringe_it = std::find(
                    fringe.begin(), fringe.end(), current);

            fringe.erase(fringe_it);

            std::vector<Node> children = this->expandEdges(current);

            fringe.insert(fringe.end(), children.begin(), children.end());

        } else {
            std::vector<Node>::iterator fringe_it = std::find(fringe.begin(),
                    fringe.end(), current);

            fringe.erase(fringe_it);
        }

    }
}
