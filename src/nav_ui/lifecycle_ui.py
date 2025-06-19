import rclpy
from rclpy.node import Node

from lifecycle_msgs.msg import State
from lifecycle_msgs.msg import Transition

from lifecycle_msgs.srv import ChangeState
from lifecycle_msgs.srv import GetState

class ControlLifecycle(Node):
    def __init__(self):
        super().__init__('control_lifecycle')