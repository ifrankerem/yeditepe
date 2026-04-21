enum Option{
		ADD_SERVICE(1),
		DISPLAY_SERVICES(2),
		TOTAL_NUM(3),
		TOTAL_WRTH(4),
		INC_PRICE(5),
		LIST_FEE_LIMIT(6),
		REMOVE_ORD(7),
		ADD_ORD(8),
		ORD_COST(9),
		EXIT(10);

	// ı created enums with constuctor for matching inputs
	
	private final int num;
	//it will not change so i declared it as final
	Option(int num)
	{
		this.num = num;
	}

	public int getNum()
	{
		return this.num;
	}

	public static Option ft_int_to_enum(int num)
	{
		//values method uses for all elements in the enum. It returns an array so ı get its length for loop
		for(int i = 0; i < Option.values().length ;i++)
		{
			Option o = Option.values()[i];
			if(o.getNum() == num)
				return o;
		}
		return null;
	}
	//this function takes user input and converts to enum numbers
	//enums in java can behave like classes unlike c so ı want to use it like this way
}
	

