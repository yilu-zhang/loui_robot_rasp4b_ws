# This Python file uses the following encoding: utf-8
"""autogenerated by genpy from rasp4b_core/SensorState.msg. Do not edit."""
import sys
python3 = True if sys.hexversion > 0x03000000 else False
import genpy
import struct


class SensorState(genpy.Message):
  _md5sum = "af96eca82971ebfe9bcfd9370b30adab"
  _type = "rasp4b_core/SensorState"
  _has_header = False #flag to mark the presence of a Header object
  _full_text = """uint8 motor_id
int16 current
int16 velocity
int16 position
int16 acclX_scaled
int16 acclY_scaled
int16 acclZ_scaled
int16 gyroX_scaled
int16 gyroY_scaled
int16 gyroZ_scaled
#double acclX_scaled
#double acclY_scaled
#double acclZ_scaled
#double gyroX_scaled
#double gyroY_scaled
#double gyroZ_scaled

"""
  __slots__ = ['motor_id','current','velocity','position','acclX_scaled','acclY_scaled','acclZ_scaled','gyroX_scaled','gyroY_scaled','gyroZ_scaled']
  _slot_types = ['uint8','int16','int16','int16','int16','int16','int16','int16','int16','int16']

  def __init__(self, *args, **kwds):
    """
    Constructor. Any message fields that are implicitly/explicitly
    set to None will be assigned a default value. The recommend
    use is keyword arguments as this is more robust to future message
    changes.  You cannot mix in-order arguments and keyword arguments.

    The available fields are:
       motor_id,current,velocity,position,acclX_scaled,acclY_scaled,acclZ_scaled,gyroX_scaled,gyroY_scaled,gyroZ_scaled

    :param args: complete set of field values, in .msg order
    :param kwds: use keyword arguments corresponding to message field names
    to set specific fields.
    """
    if args or kwds:
      super(SensorState, self).__init__(*args, **kwds)
      #message fields cannot be None, assign default values for those that are
      if self.motor_id is None:
        self.motor_id = 0
      if self.current is None:
        self.current = 0
      if self.velocity is None:
        self.velocity = 0
      if self.position is None:
        self.position = 0
      if self.acclX_scaled is None:
        self.acclX_scaled = 0
      if self.acclY_scaled is None:
        self.acclY_scaled = 0
      if self.acclZ_scaled is None:
        self.acclZ_scaled = 0
      if self.gyroX_scaled is None:
        self.gyroX_scaled = 0
      if self.gyroY_scaled is None:
        self.gyroY_scaled = 0
      if self.gyroZ_scaled is None:
        self.gyroZ_scaled = 0
    else:
      self.motor_id = 0
      self.current = 0
      self.velocity = 0
      self.position = 0
      self.acclX_scaled = 0
      self.acclY_scaled = 0
      self.acclZ_scaled = 0
      self.gyroX_scaled = 0
      self.gyroY_scaled = 0
      self.gyroZ_scaled = 0

  def _get_types(self):
    """
    internal API method
    """
    return self._slot_types

  def serialize(self, buff):
    """
    serialize message into buffer
    :param buff: buffer, ``StringIO``
    """
    try:
      _x = self
      buff.write(_get_struct_B9h().pack(_x.motor_id, _x.current, _x.velocity, _x.position, _x.acclX_scaled, _x.acclY_scaled, _x.acclZ_scaled, _x.gyroX_scaled, _x.gyroY_scaled, _x.gyroZ_scaled))
    except struct.error as se: self._check_types(struct.error("%s: '%s' when writing '%s'" % (type(se), str(se), str(locals().get('_x', self)))))
    except TypeError as te: self._check_types(ValueError("%s: '%s' when writing '%s'" % (type(te), str(te), str(locals().get('_x', self)))))

  def deserialize(self, str):
    """
    unpack serialized message in str into this message instance
    :param str: byte array of serialized message, ``str``
    """
    try:
      end = 0
      _x = self
      start = end
      end += 19
      (_x.motor_id, _x.current, _x.velocity, _x.position, _x.acclX_scaled, _x.acclY_scaled, _x.acclZ_scaled, _x.gyroX_scaled, _x.gyroY_scaled, _x.gyroZ_scaled,) = _get_struct_B9h().unpack(str[start:end])
      return self
    except struct.error as e:
      raise genpy.DeserializationError(e) #most likely buffer underfill


  def serialize_numpy(self, buff, numpy):
    """
    serialize message with numpy array types into buffer
    :param buff: buffer, ``StringIO``
    :param numpy: numpy python module
    """
    try:
      _x = self
      buff.write(_get_struct_B9h().pack(_x.motor_id, _x.current, _x.velocity, _x.position, _x.acclX_scaled, _x.acclY_scaled, _x.acclZ_scaled, _x.gyroX_scaled, _x.gyroY_scaled, _x.gyroZ_scaled))
    except struct.error as se: self._check_types(struct.error("%s: '%s' when writing '%s'" % (type(se), str(se), str(locals().get('_x', self)))))
    except TypeError as te: self._check_types(ValueError("%s: '%s' when writing '%s'" % (type(te), str(te), str(locals().get('_x', self)))))

  def deserialize_numpy(self, str, numpy):
    """
    unpack serialized message in str into this message instance using numpy for array types
    :param str: byte array of serialized message, ``str``
    :param numpy: numpy python module
    """
    try:
      end = 0
      _x = self
      start = end
      end += 19
      (_x.motor_id, _x.current, _x.velocity, _x.position, _x.acclX_scaled, _x.acclY_scaled, _x.acclZ_scaled, _x.gyroX_scaled, _x.gyroY_scaled, _x.gyroZ_scaled,) = _get_struct_B9h().unpack(str[start:end])
      return self
    except struct.error as e:
      raise genpy.DeserializationError(e) #most likely buffer underfill

_struct_I = genpy.struct_I
def _get_struct_I():
    global _struct_I
    return _struct_I
_struct_B9h = None
def _get_struct_B9h():
    global _struct_B9h
    if _struct_B9h is None:
        _struct_B9h = struct.Struct("<B9h")
    return _struct_B9h
