@[Link(ldflags: "#{__DIR__}/screen.o -lX11")]
lib LibScreen

    fun size(width : Pointer(Int32), height : Pointer(Int32)) : Void

end


@[Link(ldflags: "#{__DIR__}/mouse.o -lX11 -lXtst")]
lib LibMouse

    fun position(x : Pointer(Int32), y : Pointer(Int32)) : Void
    
    fun move_to(x : Int32, y : Int32) : Void

    fun set_mouse(button : Int32, down : Bool) : Void

    fun click(button : Int32) : Void

end


@[Link(ldflags: "#{__DIR__}/keyboard.o -lX11 -lXtst")]
lib LibKeyboard

    fun set_key(key : Int32, down : Bool) : Void

    fun press(key : Int32) : Void

end


def size()
    width = height = 0
    LibScreen.size(pointerof(width), pointerof(height))
    return width, height
end


def position()
    x = y = 0
    LibMouse.position(pointerof(x), pointerof(height))
    return x, y
end


def move_to(x, y)
    LibMouse.move_to(x, y)
end


def mouse_down(button)
    LibMouse.set_mouse(button, true)
end


def mouse_up(button)
    LibMouse.set_mouse(button, false)
end


def click(button)
    LibMouse.click(button)
end


def key_code_down(key)
    LibKeyboard.set_key(key, true)
end


def key_code_up(key)
    LibKeyboard.set_key(key, false)
end


def key_code_press(key)
    LibKeyboard.press(key)
end
