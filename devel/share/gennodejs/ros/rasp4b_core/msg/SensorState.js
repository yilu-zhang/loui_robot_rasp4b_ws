// Auto-generated. Do not edit!

// (in-package rasp4b_core.msg)


"use strict";

const _serializer = _ros_msg_utils.Serialize;
const _arraySerializer = _serializer.Array;
const _deserializer = _ros_msg_utils.Deserialize;
const _arrayDeserializer = _deserializer.Array;
const _finder = _ros_msg_utils.Find;
const _getByteLength = _ros_msg_utils.getByteLength;

//-----------------------------------------------------------

class SensorState {
  constructor(initObj={}) {
    if (initObj === null) {
      // initObj === null is a special case for deserialization where we don't initialize fields
      this.motor_id = null;
      this.current = null;
      this.velocity = null;
      this.position = null;
      this.acclX_scaled = null;
      this.acclY_scaled = null;
      this.acclZ_scaled = null;
      this.gyroX_scaled = null;
      this.gyroY_scaled = null;
      this.gyroZ_scaled = null;
    }
    else {
      if (initObj.hasOwnProperty('motor_id')) {
        this.motor_id = initObj.motor_id
      }
      else {
        this.motor_id = 0;
      }
      if (initObj.hasOwnProperty('current')) {
        this.current = initObj.current
      }
      else {
        this.current = 0;
      }
      if (initObj.hasOwnProperty('velocity')) {
        this.velocity = initObj.velocity
      }
      else {
        this.velocity = 0;
      }
      if (initObj.hasOwnProperty('position')) {
        this.position = initObj.position
      }
      else {
        this.position = 0;
      }
      if (initObj.hasOwnProperty('acclX_scaled')) {
        this.acclX_scaled = initObj.acclX_scaled
      }
      else {
        this.acclX_scaled = 0;
      }
      if (initObj.hasOwnProperty('acclY_scaled')) {
        this.acclY_scaled = initObj.acclY_scaled
      }
      else {
        this.acclY_scaled = 0;
      }
      if (initObj.hasOwnProperty('acclZ_scaled')) {
        this.acclZ_scaled = initObj.acclZ_scaled
      }
      else {
        this.acclZ_scaled = 0;
      }
      if (initObj.hasOwnProperty('gyroX_scaled')) {
        this.gyroX_scaled = initObj.gyroX_scaled
      }
      else {
        this.gyroX_scaled = 0;
      }
      if (initObj.hasOwnProperty('gyroY_scaled')) {
        this.gyroY_scaled = initObj.gyroY_scaled
      }
      else {
        this.gyroY_scaled = 0;
      }
      if (initObj.hasOwnProperty('gyroZ_scaled')) {
        this.gyroZ_scaled = initObj.gyroZ_scaled
      }
      else {
        this.gyroZ_scaled = 0;
      }
    }
  }

  static serialize(obj, buffer, bufferOffset) {
    // Serializes a message object of type SensorState
    // Serialize message field [motor_id]
    bufferOffset = _serializer.uint8(obj.motor_id, buffer, bufferOffset);
    // Serialize message field [current]
    bufferOffset = _serializer.int16(obj.current, buffer, bufferOffset);
    // Serialize message field [velocity]
    bufferOffset = _serializer.int16(obj.velocity, buffer, bufferOffset);
    // Serialize message field [position]
    bufferOffset = _serializer.int16(obj.position, buffer, bufferOffset);
    // Serialize message field [acclX_scaled]
    bufferOffset = _serializer.int16(obj.acclX_scaled, buffer, bufferOffset);
    // Serialize message field [acclY_scaled]
    bufferOffset = _serializer.int16(obj.acclY_scaled, buffer, bufferOffset);
    // Serialize message field [acclZ_scaled]
    bufferOffset = _serializer.int16(obj.acclZ_scaled, buffer, bufferOffset);
    // Serialize message field [gyroX_scaled]
    bufferOffset = _serializer.int16(obj.gyroX_scaled, buffer, bufferOffset);
    // Serialize message field [gyroY_scaled]
    bufferOffset = _serializer.int16(obj.gyroY_scaled, buffer, bufferOffset);
    // Serialize message field [gyroZ_scaled]
    bufferOffset = _serializer.int16(obj.gyroZ_scaled, buffer, bufferOffset);
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type SensorState
    let len;
    let data = new SensorState(null);
    // Deserialize message field [motor_id]
    data.motor_id = _deserializer.uint8(buffer, bufferOffset);
    // Deserialize message field [current]
    data.current = _deserializer.int16(buffer, bufferOffset);
    // Deserialize message field [velocity]
    data.velocity = _deserializer.int16(buffer, bufferOffset);
    // Deserialize message field [position]
    data.position = _deserializer.int16(buffer, bufferOffset);
    // Deserialize message field [acclX_scaled]
    data.acclX_scaled = _deserializer.int16(buffer, bufferOffset);
    // Deserialize message field [acclY_scaled]
    data.acclY_scaled = _deserializer.int16(buffer, bufferOffset);
    // Deserialize message field [acclZ_scaled]
    data.acclZ_scaled = _deserializer.int16(buffer, bufferOffset);
    // Deserialize message field [gyroX_scaled]
    data.gyroX_scaled = _deserializer.int16(buffer, bufferOffset);
    // Deserialize message field [gyroY_scaled]
    data.gyroY_scaled = _deserializer.int16(buffer, bufferOffset);
    // Deserialize message field [gyroZ_scaled]
    data.gyroZ_scaled = _deserializer.int16(buffer, bufferOffset);
    return data;
  }

  static getMessageSize(object) {
    return 19;
  }

  static datatype() {
    // Returns string type for a message object
    return 'rasp4b_core/SensorState';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return 'af96eca82971ebfe9bcfd9370b30adab';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
    uint8 motor_id
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
    
    
    `;
  }

  static Resolve(msg) {
    // deep-construct a valid message object instance of whatever was passed in
    if (typeof msg !== 'object' || msg === null) {
      msg = {};
    }
    const resolved = new SensorState(null);
    if (msg.motor_id !== undefined) {
      resolved.motor_id = msg.motor_id;
    }
    else {
      resolved.motor_id = 0
    }

    if (msg.current !== undefined) {
      resolved.current = msg.current;
    }
    else {
      resolved.current = 0
    }

    if (msg.velocity !== undefined) {
      resolved.velocity = msg.velocity;
    }
    else {
      resolved.velocity = 0
    }

    if (msg.position !== undefined) {
      resolved.position = msg.position;
    }
    else {
      resolved.position = 0
    }

    if (msg.acclX_scaled !== undefined) {
      resolved.acclX_scaled = msg.acclX_scaled;
    }
    else {
      resolved.acclX_scaled = 0
    }

    if (msg.acclY_scaled !== undefined) {
      resolved.acclY_scaled = msg.acclY_scaled;
    }
    else {
      resolved.acclY_scaled = 0
    }

    if (msg.acclZ_scaled !== undefined) {
      resolved.acclZ_scaled = msg.acclZ_scaled;
    }
    else {
      resolved.acclZ_scaled = 0
    }

    if (msg.gyroX_scaled !== undefined) {
      resolved.gyroX_scaled = msg.gyroX_scaled;
    }
    else {
      resolved.gyroX_scaled = 0
    }

    if (msg.gyroY_scaled !== undefined) {
      resolved.gyroY_scaled = msg.gyroY_scaled;
    }
    else {
      resolved.gyroY_scaled = 0
    }

    if (msg.gyroZ_scaled !== undefined) {
      resolved.gyroZ_scaled = msg.gyroZ_scaled;
    }
    else {
      resolved.gyroZ_scaled = 0
    }

    return resolved;
    }
};

module.exports = SensorState;
