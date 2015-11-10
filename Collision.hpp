#ifndef COLLISION_HEADER
#define COLLISION_HEADER

class Collision {
public:
    static bool CircleToRectangle (const float &cx, const float &cy, const float &cr,
                                   const float &bx, const float &by, const float &bw,
                                   const float &bh) {
                                       if (cx < bx + bw &&
                                           cx + cr > + bx &&
                                           cy < by + bh &&
                                           cy + cr > by)
                                            return true;

                                        return false;
                                   }

                                   // x > bx && x < bx + bw && y > by && y < y + bh

    static bool CircleToTile (const float  &cx, const float &cy, const float &bx, const float &by,
                                                const float &bw, const float &bh) {
                                        if (cx > bx &&
                                            cx < bx + bw &&
                                            cy > by &&
                                            cy < by + bh)
                                                return true;

                                        return false;
                                    }

    /** TO DO TRY TO FIX

    static bool checkWindowIntersect (const float &minWidth, const float &bx) {
                                     if (minWidth >= bx)
                                        return true;

                                     return false;
                                 }

    static bool checkWindowIntersect (const float &maxWidth, const float &bx, const float &bh) {
                                     if (maxWidth <= bx + bh)
                                        return true;

                                     return false;
                                 }

    **/

};

#endif // COLLISION_HEADER
