for (int i = 0; i < n; ++i) swap(p[rand()%n], p[rand()%n]);
r = 0;
cir = p[0];
for (int i = 0; i < n; ++i) {
    if (dcmp(Distance(cir, p[i]) - r) <= 0) continue;
    cir = (p[0] + p[i]) * 0.5;
    r = Distance(p[0], p[i]) * 0.5;
    for (int j = 1; j < i; ++j) {
        if (dcmp(Distance(cir, p[j]) - r) <= 0) continue;
        cir = (p[i] + p[j]) * 0.5;
        r = Distance(p[i], p[j]) * 0.5;
        for (int k = 0; k < j; ++k) {
            if (dcmp(Distance(cir, p[k]) - r) <= 0) continue;
            Circle(p[i], p[j], p[k], cir);
            r = Distance(cir, p[i]);
        }
    }
}