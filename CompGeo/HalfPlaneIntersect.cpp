/*
 * input: Array of lines
 * output: the points of intersection
 * Time: O(nlogn)
 */
deque<Line> Q;
deque<Point> Qp;
vector<Point> halfPlaneCross(vector<Line> &ls) {
    while (!Q.empty()) Q.pop_front();
    while (!Qp.empty()) Qp.pop_front();
    sort(ALL(ls), cmp);
    Q.push_back(ls[0]);
    for (int i = 1; i < SZ(ls); ++i) {
        if (dcmp(Cross(ls[i].getdir(), ls[i-1].getdir())) != 0) {
            while (!Qp.empty() && !onLeft(ls[i], Qp.back())) Q.pop_back(), Qp.pop_back();
            while (!Qp.empty() && !onLeft(ls[i], Qp.front())) Q.pop_front(), Qp.pop_front();
            Point tmp;
            intersect(Q.back(), ls[i], tmp);
            Q.push_back(ls[i]);
            Qp.push_back(tmp);
        }
    }
    while (!Qp.empty() && !onLeft(Q.front(), Qp.back())) Q.pop_back(), Qp.pop_back();
    vector<Point> ansp;
    if (Qp.size() <= 1) return ansp;
    ansp.PB(Point());
    intersect(Q.front(), Q.back(), ansp[0]);
    while (!Qp.empty()) ansp.PB(Qp.front()), Qp.pop_front();
    return ansp;
}