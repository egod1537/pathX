using System.Runtime.CompilerServices;
using UnityEngine;

namespace PathX
{
    public class ViewProjectionCamera : MonoBehaviour
    {
        private ViewProbeJSON _model;
        public ViewProbeJSON model { get => _model ??= transform.parent.GetComponent<ViewProbeJSON>(); }

        public ViewPlane viewPlane { get => new ViewPlane(transform.position, transform.forward); }

        public void OnDrawGizmos()
        {
            Gizmos.matrix = transform.localToWorldMatrix;
            {
                Gizmos.color = Color.red;
                {
                    Gizmos.DrawSphere(Vector3.zero, 0.25f);
                }

                Gizmos.color = new Color(1f, 1f, 1f, 0.5f);
                {
                    Gizmos.DrawCube(Vector3.zero, model.world);
                    Gizmos.DrawCube(Vector3.forward * model.viewDistance, model.world);
                    Gizmos.DrawWireCube(Vector3.forward * model.viewDistance / 2, new Vector3(model.world.x, model.world.y, model.viewDistance));
                }

                Gizmos.color = Color.yellow;
                {
                    Gizmos.DrawLine(Vector3.zero, Vector3.forward * model.viewDistance);
                }
                Gizmos.color = Color.white;
            }
            Gizmos.matrix = Matrix4x4.identity;
        }
    }
}