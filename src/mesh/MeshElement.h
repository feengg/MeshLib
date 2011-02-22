#ifndef MESHLIB_MESHELEMENT_H_
#define MESHLIB_MESHELEMENT_H_

#include "../common/types.h"

namespace MeshLib{

    typedef int Handle;
    
    typedef Handle VertHandle;
    typedef Handle FaceHandle;
    typedef Handle EdgeHandle;
    typedef Handle HalfEdgeHandle;

    enum VERTFLAG{
        ISOLATED = 0x00000100, // isolated vertex flag
        MANIFOLD = 0x00000200, // manifold vertex flag
        BOUNDARY = 0x00000400  // boundary vertex flag
    };
    enum FACEFLAG{
        BOUNDARY = 0x00000100,
        MANIFOLD = 0x00000200
    };
    enum EDGEFLAG{
        BOUNDARY = 0x00000100,
        MANIFOLD = 0x00000200
    };
    enum MESHFLAG{
        TRIMESH = 0x00000100,
        QUADMESH = 0x00000200,
        POLYMESH = 0x00000400,

        MANIFOLD = 0x00000800
    };
    
    class Vert
    {        
    public:
        Normal normal;
        Color  color;        
        Coord3D coord;
        VERTFLAG flag; // flag bits
        HalfEdgeHandle he_handle; 
    };

    class Face
    {
    public:
        std::vector<VertHandle> vert_handle_vec;
        Normal normal;
        FACEFLAG flag;
    };

    class Edge
    {
    public:
        HalfEdgeHandle he_handle_1;
        HalfEdgeHandle he_handle_2;

        EDGEFLAG flag;
    };

    class HalfEdge
    {
    public:
        HalfEdge();
        ~HalfEdge();
        
    public:
        HalfEdgeHandle prev_he_handle; /// previous halfedge
        HalfEdgeHandle next_he_handle; /// next halfedge
        HalfEdgeHandle oppo_he_handle; /// opposite halfedge

        VertHandle vert_handle; /// vertex of halfedge
        FaceHandle face_handle; /// face of halfedge, -1 if boundary halfedge
        EdgeHandle edge_handle; /// edge of halfedge
    }
    

    class ModelInfo
    {
    public:
        MESHFLAG flag;

        bool IsTriMesh() const;
        bool IsQuadMesh() const;
        bool IsPolyMesh() const;
        bool IsManifold() const;
    }
}

#endif
