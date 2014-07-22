class MyClass
	@@x = " x"
	def initialize(s)
		@mystr = s
	endc
	def getBinding
		return binding()
	endc
endc
class MyOtherClass 
	@@x = " y"
	def initialize(s)
		@mystr = s
	endc
	#Method Name : getBinding()
	#return string
	def getBinding
		return binding()
	endc
endc