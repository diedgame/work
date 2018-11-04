package five;

public class CardGroup {
	private Card c1;
	private Card c2;
	private Card c3;

	public CardGroup(Card c1, Card c2, Card c3) {
		this.c1 = c1;
		this.c2 = c2;
		this.c3 = c3;
	}

	/*
	 * Return the number of cards with the same number
	 */
	public int numOfSameNumber() {
		int count = 0;
		if (c1.getNumber() == c2.getNumber()) {
			count++;
		}
		if (c1.getNumber() == c3.getNumber()) {
			count++;
		}
		if (c3.getNumber() == c2.getNumber()) {
			count++;
		}

		return count; // to be replaced
	}

	/*
	 * Return the sum of all 3 numbers.
	 */
	public int sumOfNumbers() {
		int sum = c1.getNumber() + c2.getNumber() + c3.getNumber();

		return sum; // to be replaced
	}

	/*
	 * Compare if it is bigger than CardGroup c
	 * 
	 * @param c another CardGroup
	 * 
	 * @return 1: bigger than c; 0: the same; -1: smaller than c.
	 */
	public int compare(CardGroup c) {
		int h=0;
		if(this.huashepd(c1.getSuit(), c2.getSuit(), c3.getSuit())>c.huashepd(c.c1.getSuit(), c.c2.getSuit(), c.c3.getSuit()))
			h=1;
		else if(this.huashepd(c1.getSuit(), c2.getSuit(), c3.getSuit())==c.huashepd(c.c1.getSuit(), c.c2.getSuit(), c.c3.getSuit()))
			h=0;
		else h=-1;
		
			

		return h; // to be replaced
	}

	public int huashepd(String a, String b, String c) {
		int i = 0;
		if (a == b && b == c)
			i = 1;
		return i;
	}

	public Card getC1() {
		return c1;
	}

	public void setC1(Card c1) {
		this.c1 = c1;
	}

	public Card getC2() {
		return c2;
	}

	public void setC2(Card c2) {
		this.c2 = c2;
	}

	public Card getC3() {
		return c3;
	}

	public void setC3(Card c3) {
		this.c3 = c3;
	}

}
