package five;

import java.util.ArrayList;
import java.util.Random;

public class Deck {
	private ArrayList<Card> cards;
	Random random;

	public Deck() {
		this.cards = new ArrayList<Card>();
		this.random = new Random();

		// create all the cards
		this.generateDeck();
	}

	/*
	 * Generate all the cards for a deck the cards are stored in the member variable
	 * - cards
	 */
	private void generateDeck() {
		for (int i = 1; i < 14; i++) {
			Card card = new Card(i, "Heart");
			cards.add(card);
		}
		for (int i = 14; i < 27; i++) {
			Card card = new Card(i, "Spade");
			cards.add(card);
		}
		for (int i = 27; i < 40; i++) {
			Card card = new Card(i, "Diamond");
			cards.add(card);
		}
		for (int i = 40; i < 53; i++) {
			Card card = new Card(i, "Club");
			cards.add(card);
		}
	}

	/*
	 * Return a random card, remove it from the deck
	 */
	public int getRandomCard() {
		int index = random.nextInt(cards.size() - 1);
		this.cards.remove(index);
		return index;
	}

	public String getRandomCard1() {
		int i = random.nextInt(3);
		String s;
		if (i == 0)
			s = "Club";
		else if (i == 1)
			s = "Heart";
		else if (i == 2)
			s = "Spade";
		else
			s = "diamond";
		return s;

	}

	/*
	 * Create a CardGroup by picking 3 cards randomly
	 */
	public CardGroup createRandomCardGroup() {
		int a = getRandomCard();
		Card c1 = new Card(a, cards.get(a).getSuit());
		int b = getRandomCard();
		Card c2 = new Card(b, cards.get(b).getSuit());
		int c = getRandomCard();
		Card c3 = new Card(c, cards.get(c).getSuit());

		CardGroup cg = new CardGroup(c1, c2, c3); // to be replaced
		return cg;
	}

	public void compare(CardGroup a, CardGroup b) {
		if (a.compare(b) > 0)
			System.out.println("前者大于后者");
		else if (a.compare(b) < 0)
			System.out.println("前者小于后者");
		else if (a.compare(b) == 0) {
			if (a.numOfSameNumber() > b.numOfSameNumber())
				System.out.println("前者大于后者");
			else if (a.numOfSameNumber() == b.numOfSameNumber())
				System.out.println("前者等于后者");
			else if (a.numOfSameNumber() < b.numOfSameNumber())
				System.out.println("前者小于后者");

		}

	}

	public static void main(String[] args) {
		Deck deck = new Deck();
		CardGroup cg1 = deck.createRandomCardGroup();
		CardGroup cg2 = deck.createRandomCardGroup();
		CardGroup cg3 = deck.createRandomCardGroup();
		deck.compare(cg3, cg1);

	}
}
