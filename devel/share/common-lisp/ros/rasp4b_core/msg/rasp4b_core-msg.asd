
(cl:in-package :asdf)

(defsystem "rasp4b_core-msg"
  :depends-on (:roslisp-msg-protocol :roslisp-utils )
  :components ((:file "_package")
    (:file "SensorState" :depends-on ("_package_SensorState"))
    (:file "_package_SensorState" :depends-on ("_package"))
  ))