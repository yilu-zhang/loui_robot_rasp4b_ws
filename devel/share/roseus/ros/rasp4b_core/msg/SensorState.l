;; Auto-generated. Do not edit!


(when (boundp 'rasp4b_core::SensorState)
  (if (not (find-package "RASP4B_CORE"))
    (make-package "RASP4B_CORE"))
  (shadow 'SensorState (find-package "RASP4B_CORE")))
(unless (find-package "RASP4B_CORE::SENSORSTATE")
  (make-package "RASP4B_CORE::SENSORSTATE"))

(in-package "ROS")
;;//! \htmlinclude SensorState.msg.html


(defclass rasp4b_core::SensorState
  :super ros::object
  :slots (_motor_id _current _velocity _position _acclX_scaled _acclY_scaled _acclZ_scaled _gyroX_scaled _gyroY_scaled _gyroZ_scaled ))

(defmethod rasp4b_core::SensorState
  (:init
   (&key
    ((:motor_id __motor_id) 0)
    ((:current __current) 0)
    ((:velocity __velocity) 0)
    ((:position __position) 0)
    ((:acclX_scaled __acclX_scaled) 0)
    ((:acclY_scaled __acclY_scaled) 0)
    ((:acclZ_scaled __acclZ_scaled) 0)
    ((:gyroX_scaled __gyroX_scaled) 0)
    ((:gyroY_scaled __gyroY_scaled) 0)
    ((:gyroZ_scaled __gyroZ_scaled) 0)
    )
   (send-super :init)
   (setq _motor_id (round __motor_id))
   (setq _current (round __current))
   (setq _velocity (round __velocity))
   (setq _position (round __position))
   (setq _acclX_scaled (round __acclX_scaled))
   (setq _acclY_scaled (round __acclY_scaled))
   (setq _acclZ_scaled (round __acclZ_scaled))
   (setq _gyroX_scaled (round __gyroX_scaled))
   (setq _gyroY_scaled (round __gyroY_scaled))
   (setq _gyroZ_scaled (round __gyroZ_scaled))
   self)
  (:motor_id
   (&optional __motor_id)
   (if __motor_id (setq _motor_id __motor_id)) _motor_id)
  (:current
   (&optional __current)
   (if __current (setq _current __current)) _current)
  (:velocity
   (&optional __velocity)
   (if __velocity (setq _velocity __velocity)) _velocity)
  (:position
   (&optional __position)
   (if __position (setq _position __position)) _position)
  (:acclX_scaled
   (&optional __acclX_scaled)
   (if __acclX_scaled (setq _acclX_scaled __acclX_scaled)) _acclX_scaled)
  (:acclY_scaled
   (&optional __acclY_scaled)
   (if __acclY_scaled (setq _acclY_scaled __acclY_scaled)) _acclY_scaled)
  (:acclZ_scaled
   (&optional __acclZ_scaled)
   (if __acclZ_scaled (setq _acclZ_scaled __acclZ_scaled)) _acclZ_scaled)
  (:gyroX_scaled
   (&optional __gyroX_scaled)
   (if __gyroX_scaled (setq _gyroX_scaled __gyroX_scaled)) _gyroX_scaled)
  (:gyroY_scaled
   (&optional __gyroY_scaled)
   (if __gyroY_scaled (setq _gyroY_scaled __gyroY_scaled)) _gyroY_scaled)
  (:gyroZ_scaled
   (&optional __gyroZ_scaled)
   (if __gyroZ_scaled (setq _gyroZ_scaled __gyroZ_scaled)) _gyroZ_scaled)
  (:serialization-length
   ()
   (+
    ;; uint8 _motor_id
    1
    ;; int16 _current
    2
    ;; int16 _velocity
    2
    ;; int16 _position
    2
    ;; int16 _acclX_scaled
    2
    ;; int16 _acclY_scaled
    2
    ;; int16 _acclZ_scaled
    2
    ;; int16 _gyroX_scaled
    2
    ;; int16 _gyroY_scaled
    2
    ;; int16 _gyroZ_scaled
    2
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; uint8 _motor_id
       (write-byte _motor_id s)
     ;; int16 _current
       (write-word _current s)
     ;; int16 _velocity
       (write-word _velocity s)
     ;; int16 _position
       (write-word _position s)
     ;; int16 _acclX_scaled
       (write-word _acclX_scaled s)
     ;; int16 _acclY_scaled
       (write-word _acclY_scaled s)
     ;; int16 _acclZ_scaled
       (write-word _acclZ_scaled s)
     ;; int16 _gyroX_scaled
       (write-word _gyroX_scaled s)
     ;; int16 _gyroY_scaled
       (write-word _gyroY_scaled s)
     ;; int16 _gyroZ_scaled
       (write-word _gyroZ_scaled s)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; uint8 _motor_id
     (setq _motor_id (sys::peek buf ptr- :char)) (incf ptr- 1)
   ;; int16 _current
     (setq _current (sys::peek buf ptr- :short)) (incf ptr- 2)
   ;; int16 _velocity
     (setq _velocity (sys::peek buf ptr- :short)) (incf ptr- 2)
   ;; int16 _position
     (setq _position (sys::peek buf ptr- :short)) (incf ptr- 2)
   ;; int16 _acclX_scaled
     (setq _acclX_scaled (sys::peek buf ptr- :short)) (incf ptr- 2)
   ;; int16 _acclY_scaled
     (setq _acclY_scaled (sys::peek buf ptr- :short)) (incf ptr- 2)
   ;; int16 _acclZ_scaled
     (setq _acclZ_scaled (sys::peek buf ptr- :short)) (incf ptr- 2)
   ;; int16 _gyroX_scaled
     (setq _gyroX_scaled (sys::peek buf ptr- :short)) (incf ptr- 2)
   ;; int16 _gyroY_scaled
     (setq _gyroY_scaled (sys::peek buf ptr- :short)) (incf ptr- 2)
   ;; int16 _gyroZ_scaled
     (setq _gyroZ_scaled (sys::peek buf ptr- :short)) (incf ptr- 2)
   ;;
   self)
  )

(setf (get rasp4b_core::SensorState :md5sum-) "af96eca82971ebfe9bcfd9370b30adab")
(setf (get rasp4b_core::SensorState :datatype-) "rasp4b_core/SensorState")
(setf (get rasp4b_core::SensorState :definition-)
      "uint8 motor_id
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


")



(provide :rasp4b_core/SensorState "af96eca82971ebfe9bcfd9370b30adab")


