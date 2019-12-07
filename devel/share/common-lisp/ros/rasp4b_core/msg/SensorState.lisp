; Auto-generated. Do not edit!


(cl:in-package rasp4b_core-msg)


;//! \htmlinclude SensorState.msg.html

(cl:defclass <SensorState> (roslisp-msg-protocol:ros-message)
  ((motor_id
    :reader motor_id
    :initarg :motor_id
    :type cl:fixnum
    :initform 0)
   (current
    :reader current
    :initarg :current
    :type cl:fixnum
    :initform 0)
   (velocity
    :reader velocity
    :initarg :velocity
    :type cl:fixnum
    :initform 0)
   (position
    :reader position
    :initarg :position
    :type cl:fixnum
    :initform 0)
   (acclX_scaled
    :reader acclX_scaled
    :initarg :acclX_scaled
    :type cl:fixnum
    :initform 0)
   (acclY_scaled
    :reader acclY_scaled
    :initarg :acclY_scaled
    :type cl:fixnum
    :initform 0)
   (acclZ_scaled
    :reader acclZ_scaled
    :initarg :acclZ_scaled
    :type cl:fixnum
    :initform 0)
   (gyroX_scaled
    :reader gyroX_scaled
    :initarg :gyroX_scaled
    :type cl:fixnum
    :initform 0)
   (gyroY_scaled
    :reader gyroY_scaled
    :initarg :gyroY_scaled
    :type cl:fixnum
    :initform 0)
   (gyroZ_scaled
    :reader gyroZ_scaled
    :initarg :gyroZ_scaled
    :type cl:fixnum
    :initform 0))
)

(cl:defclass SensorState (<SensorState>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <SensorState>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'SensorState)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name rasp4b_core-msg:<SensorState> is deprecated: use rasp4b_core-msg:SensorState instead.")))

(cl:ensure-generic-function 'motor_id-val :lambda-list '(m))
(cl:defmethod motor_id-val ((m <SensorState>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader rasp4b_core-msg:motor_id-val is deprecated.  Use rasp4b_core-msg:motor_id instead.")
  (motor_id m))

(cl:ensure-generic-function 'current-val :lambda-list '(m))
(cl:defmethod current-val ((m <SensorState>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader rasp4b_core-msg:current-val is deprecated.  Use rasp4b_core-msg:current instead.")
  (current m))

(cl:ensure-generic-function 'velocity-val :lambda-list '(m))
(cl:defmethod velocity-val ((m <SensorState>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader rasp4b_core-msg:velocity-val is deprecated.  Use rasp4b_core-msg:velocity instead.")
  (velocity m))

(cl:ensure-generic-function 'position-val :lambda-list '(m))
(cl:defmethod position-val ((m <SensorState>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader rasp4b_core-msg:position-val is deprecated.  Use rasp4b_core-msg:position instead.")
  (position m))

(cl:ensure-generic-function 'acclX_scaled-val :lambda-list '(m))
(cl:defmethod acclX_scaled-val ((m <SensorState>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader rasp4b_core-msg:acclX_scaled-val is deprecated.  Use rasp4b_core-msg:acclX_scaled instead.")
  (acclX_scaled m))

(cl:ensure-generic-function 'acclY_scaled-val :lambda-list '(m))
(cl:defmethod acclY_scaled-val ((m <SensorState>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader rasp4b_core-msg:acclY_scaled-val is deprecated.  Use rasp4b_core-msg:acclY_scaled instead.")
  (acclY_scaled m))

(cl:ensure-generic-function 'acclZ_scaled-val :lambda-list '(m))
(cl:defmethod acclZ_scaled-val ((m <SensorState>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader rasp4b_core-msg:acclZ_scaled-val is deprecated.  Use rasp4b_core-msg:acclZ_scaled instead.")
  (acclZ_scaled m))

(cl:ensure-generic-function 'gyroX_scaled-val :lambda-list '(m))
(cl:defmethod gyroX_scaled-val ((m <SensorState>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader rasp4b_core-msg:gyroX_scaled-val is deprecated.  Use rasp4b_core-msg:gyroX_scaled instead.")
  (gyroX_scaled m))

(cl:ensure-generic-function 'gyroY_scaled-val :lambda-list '(m))
(cl:defmethod gyroY_scaled-val ((m <SensorState>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader rasp4b_core-msg:gyroY_scaled-val is deprecated.  Use rasp4b_core-msg:gyroY_scaled instead.")
  (gyroY_scaled m))

(cl:ensure-generic-function 'gyroZ_scaled-val :lambda-list '(m))
(cl:defmethod gyroZ_scaled-val ((m <SensorState>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader rasp4b_core-msg:gyroZ_scaled-val is deprecated.  Use rasp4b_core-msg:gyroZ_scaled instead.")
  (gyroZ_scaled m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <SensorState>) ostream)
  "Serializes a message object of type '<SensorState>"
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'motor_id)) ostream)
  (cl:let* ((signed (cl:slot-value msg 'current)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 65536) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) unsigned) ostream)
    )
  (cl:let* ((signed (cl:slot-value msg 'velocity)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 65536) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) unsigned) ostream)
    )
  (cl:let* ((signed (cl:slot-value msg 'position)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 65536) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) unsigned) ostream)
    )
  (cl:let* ((signed (cl:slot-value msg 'acclX_scaled)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 65536) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) unsigned) ostream)
    )
  (cl:let* ((signed (cl:slot-value msg 'acclY_scaled)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 65536) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) unsigned) ostream)
    )
  (cl:let* ((signed (cl:slot-value msg 'acclZ_scaled)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 65536) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) unsigned) ostream)
    )
  (cl:let* ((signed (cl:slot-value msg 'gyroX_scaled)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 65536) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) unsigned) ostream)
    )
  (cl:let* ((signed (cl:slot-value msg 'gyroY_scaled)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 65536) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) unsigned) ostream)
    )
  (cl:let* ((signed (cl:slot-value msg 'gyroZ_scaled)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 65536) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) unsigned) ostream)
    )
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <SensorState>) istream)
  "Deserializes a message object of type '<SensorState>"
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'motor_id)) (cl:read-byte istream))
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'current) (cl:if (cl:< unsigned 32768) unsigned (cl:- unsigned 65536))))
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'velocity) (cl:if (cl:< unsigned 32768) unsigned (cl:- unsigned 65536))))
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'position) (cl:if (cl:< unsigned 32768) unsigned (cl:- unsigned 65536))))
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'acclX_scaled) (cl:if (cl:< unsigned 32768) unsigned (cl:- unsigned 65536))))
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'acclY_scaled) (cl:if (cl:< unsigned 32768) unsigned (cl:- unsigned 65536))))
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'acclZ_scaled) (cl:if (cl:< unsigned 32768) unsigned (cl:- unsigned 65536))))
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'gyroX_scaled) (cl:if (cl:< unsigned 32768) unsigned (cl:- unsigned 65536))))
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'gyroY_scaled) (cl:if (cl:< unsigned 32768) unsigned (cl:- unsigned 65536))))
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'gyroZ_scaled) (cl:if (cl:< unsigned 32768) unsigned (cl:- unsigned 65536))))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<SensorState>)))
  "Returns string type for a message object of type '<SensorState>"
  "rasp4b_core/SensorState")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'SensorState)))
  "Returns string type for a message object of type 'SensorState"
  "rasp4b_core/SensorState")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<SensorState>)))
  "Returns md5sum for a message object of type '<SensorState>"
  "af96eca82971ebfe9bcfd9370b30adab")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'SensorState)))
  "Returns md5sum for a message object of type 'SensorState"
  "af96eca82971ebfe9bcfd9370b30adab")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<SensorState>)))
  "Returns full string definition for message of type '<SensorState>"
  (cl:format cl:nil "uint8 motor_id~%int16 current~%int16 velocity~%int16 position~%int16 acclX_scaled~%int16 acclY_scaled~%int16 acclZ_scaled~%int16 gyroX_scaled~%int16 gyroY_scaled~%int16 gyroZ_scaled~%#double acclX_scaled~%#double acclY_scaled~%#double acclZ_scaled~%#double gyroX_scaled~%#double gyroY_scaled~%#double gyroZ_scaled~%~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'SensorState)))
  "Returns full string definition for message of type 'SensorState"
  (cl:format cl:nil "uint8 motor_id~%int16 current~%int16 velocity~%int16 position~%int16 acclX_scaled~%int16 acclY_scaled~%int16 acclZ_scaled~%int16 gyroX_scaled~%int16 gyroY_scaled~%int16 gyroZ_scaled~%#double acclX_scaled~%#double acclY_scaled~%#double acclZ_scaled~%#double gyroX_scaled~%#double gyroY_scaled~%#double gyroZ_scaled~%~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <SensorState>))
  (cl:+ 0
     1
     2
     2
     2
     2
     2
     2
     2
     2
     2
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <SensorState>))
  "Converts a ROS message object to a list"
  (cl:list 'SensorState
    (cl:cons ':motor_id (motor_id msg))
    (cl:cons ':current (current msg))
    (cl:cons ':velocity (velocity msg))
    (cl:cons ':position (position msg))
    (cl:cons ':acclX_scaled (acclX_scaled msg))
    (cl:cons ':acclY_scaled (acclY_scaled msg))
    (cl:cons ':acclZ_scaled (acclZ_scaled msg))
    (cl:cons ':gyroX_scaled (gyroX_scaled msg))
    (cl:cons ':gyroY_scaled (gyroY_scaled msg))
    (cl:cons ':gyroZ_scaled (gyroZ_scaled msg))
))
