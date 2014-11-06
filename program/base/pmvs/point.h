#ifndef PMVS3_POINT_H
#define PMVS3_POINT_H

#include "../numeric/vec4.h"
#include "../numeric/mat3.h"

namespace PMVS3 {
class Cpoint {
 public:
  Cpoint(void);
  virtual ~Cpoint();
  
  Vec3f m_icoord;
  float m_response;

  // 0: Harris
  // 1: DoG
  int m_type;

  // tempporary variable, used to store original imageid in initial match
  int m_imgeid;
  // 3D coordinate
  Vec4f m_coord;
#ifdef HYX_TEST
  int pointid;
#endif
  bool operator < (const Cpoint& rhs) const {
    return m_response < rhs.m_response;
  }

  friend std::istream& operator >>(std::istream& istr, Cpoint& rhs);
  friend std::ostream& operator <<(std::ostream& ostr, const Cpoint& rhs);
};

bool SortCpoint(const Cpoint& a, const Cpoint& b);

std::istream& operator >>(std::istream& istr, Cpoint& rhs);
std::ostream& operator <<(std::ostream& ostr, const Cpoint& rhs);
};

#endif //PMVS3_POINT_H
