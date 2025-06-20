import rclpy
from rclpy.node import Node

from lifecycle_msgs.msg import State
from lifecycle_msgs.msg import Transition

from lifecycle_msgs.srv import ChangeState
from lifecycle_msgs.srv import GetState

class ControlLifecycle(Node):
    def __init__(self):
        super().__init__('control_lifecycle')
        self.lifecycle_service = self.create_client(
            ChangeState,
            '/joy_vel_converter/change_state'
        )
        self.get_req = GetState.Request()
        self.change_req = ChangeState.Request()

    def send_request(self, id):
        self.change_req.transition.id = id
        self.future = self.lifecycle_service.call_async(self.change_req)
        rclpy.spin_until_future_complete(self, self.future)
        return self.future.result()

def main_control_lifecycle(args=None):
    rclpy.init(args=args)

    control_lifecycle = ControlLifecycle()
    response = control_lifecycle.send_request(Transition.TRANSITION_CONFIGURE)
    control_lifecycle.get_logger().info(str(response))