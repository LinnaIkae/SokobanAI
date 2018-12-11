#include "BFS_Solver.hpp"
#include "Grid.hpp"
#include <chrono>

using namespace std::chrono;

BFS_Solver::BFS_Solver() {
};

BFS_Solver::BFS_Solver(std::vector<std::string> lines) :
Solver(lines) {
    first_step_done = false;
};

BFS_Solver::BFS_Solver(const BFS_Solver& orig) {
}

BFS_Solver::~BFS_Solver() {
}

Node BFS_Solver::popFringe() {

    Node n = this->fringe.front();

    const std::vector<Node>::iterator fringe_it = std::find(
            fringe.begin(), fringe.end(), n);

    fringe.erase(fringe_it);
    return n;
}

bool BFS_Solver::searchStep(Grid& g, sf::RenderWindow& window) {

    if (!first_step_done) {
        //auto start = std::chrono::high_resolution_clock::now();
        current = Node(this->agent, this->boxes);
        g.draw(window, current);
        fringe.clear();
        this->fringe.push_back(current);
        std::cout << "First Node: " << std::endl;
        current.debugPrint();
        first_step_done = true;
        return false;
    } else {

        if (this->fringe.empty()) {
            std::cout << "Failed to find solution" << std::endl;
            //auto stop = std::chrono::high_resolution_clock::now();
            //auto duration = std::chrono::duration_cast<milliseconds>(stop - start);
            //std::cout << "Time(ms) :" << duration.count() << std::endl;
            return true;
        }

        //eli tässä kun current muutetaan, se säilyttää saman oman osoitteen,
        //jolloin se on oman itsensä parent.

        //TODO: keksi keino miten tämä korjataan.
        current = this->popFringe();

        g.draw(window, current);
        //std::cout << "current: " << std::endl;
        //current.debugPrint();

        if (goalCheck(current)) {
            for (auto n : retracePath(&current)) {
                std::cout << "node on the path: " << (*n).agent.x << (*n).agent.y << std::endl;
            }
            //auto stop = std::chrono::high_resolution_clock::now();
            //auto duration = std::chrono::duration_cast<milliseconds>(stop - start);
            //std::cout << "Time(ms) :" << duration.count() << std::endl;
            return true;

        }
        //check if not in closed
        if (std::find(closed.begin(), closed.end(), current) == closed.end()) {
            closed.push_back(current);

            std::vector<Node> children = this->expandEdges(current);

            fringe.insert(fringe.end(), children.begin(), children.end());

        }
        return false;

    }
}
