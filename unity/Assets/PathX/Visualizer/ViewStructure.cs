using System;
using System.Collections.Generic;
using UnityEngine;

namespace PathX
{
    public class ViewPlane
    {
        public Vector3 normal;
        public Vector3 origin;

        public ViewPlane(Vector3 normal, Vector3 origin)
        {
            this.normal = normal;
            this.origin = origin;
        }

        public Vector3 ProjectPoint(Vector3 point)
        {
            Vector3 toPoint = point - origin;
            float dist = Vector3.Dot(toPoint, normal);
            return point - normal * dist;
        }

        public Vector2 Project2DPoint(Vector3 point)
        {
            Vector3 projected = ProjectPoint(point);

            Vector3 U = Vector3.Cross(normal, Vector3.up);
            if (U.sqrMagnitude < 1e-6f)
                U = Vector3.Cross(normal, Vector3.right);
            U.Normalize();
            Vector3 V = Vector3.Cross(normal, U);

            Vector3 delta = projected - origin;
            float x = Vector3.Dot(delta, U);
            float y = Vector3.Dot(delta, V);
            return new Vector2(x, y);
        }
    }

    [Serializable]
    public class ViewGameObject
    {
        public string name;
        [SerializeField]
        public List<Vector2> vertices;

        public ViewGameObject(string name, List<Vector2> vertices)
        {
            this.name = name;
            this.vertices = vertices;
        }
    }

    [Serializable]
    public class ViewJSON
    {
        [SerializeField]
        public Vector2 world;
        [SerializeField]
        public List<ViewGameObject> gameObjects;
    }
}