#ifndef Various_Tools_ITEMS_H
#define Various_Tools_ITEMS_H

#include <mepp_config.h>
#ifdef BUILD_component_Various_Tools

#include "../../../../mepp/Polyhedron/polyhedron_shared_items.h"

template <class Refs, class T, class P, class Norm, class Plane>
class Various_Tools_Facet : virtual public MEPP_Common_Facet<Refs, T, Norm>
{
	public:

		Various_Tools_Facet() {}
};


template <class Refs, class Tprev, class Tvertex, class Tface, class Norm>
class Various_Tools_Halfedge : virtual public MEPP_Common_Halfedge<Refs,Tprev,Tvertex,Tface,Norm>
{
	public:

		Various_Tools_Halfedge() {}
};


template <class Refs, class T, class P, class Norm>
class Various_Tools_Vertex : virtual public MEPP_Common_Vertex<Refs, T, P, Norm>
{
	public:

		Various_Tools_Vertex() {}
};


template <class kernel, class items>
class Various_Tools_Polyhedron : virtual public MEPP_Common_Polyhedron<kernel,items>
{
	public:

		Various_Tools_Polyhedron() {}
};

#endif

#endif // Various_Tools_ITEMS_H
