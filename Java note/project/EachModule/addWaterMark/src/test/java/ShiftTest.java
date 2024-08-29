package com.yardland.cargill.onecard.sender;

import java.util.Date;

import com.yardland.commons.util.Utils;

public class ShiftTest {

	public static void main(String[] args) {
		long stamp = System.currentTimeMillis();
		Date today = Utils.getToday();
		Long mins = (stamp - today.getTime()) / 60000l;
		System.out.println(mins);
	}

	private static long test(long stamp) {
		Date today = Utils.getToday();
		Long mins = (stamp - today.getTime() - 1) / 60000l + 1;
		return mins;
	}

}

