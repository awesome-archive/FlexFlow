#ifndef _FLEXFLOW_REDUCTION_ATTRS_H
#define _FLEXFLOW_REDUCTION_ATTRS_H

#include "op-attrs/parallel_tensor_shape.h"
#include "utils/visitable.h"
#include "op-attrs/ff_dim.h"

namespace FlexFlow {

struct ReductionAttrs : public use_visitable_eq<ReductionAttrs> {
public:
  ReductionAttrs(ff_dim_t reduction_dim, int reduction_degree);
public:
  ff_dim_t reduction_dim;
  int reduction_degree;
};

}

VISITABLE_STRUCT(::FlexFlow::ReductionAttrs, reduction_dim, reduction_degree);
MAKE_VISIT_HASHABLE(::FlexFlow::ReductionAttrs);

#endif 
