package com.mhy;

import com.mhy.beans1.Learn1;
import org.springframework.context.ApplicationContext;
import org.springframework.context.support.ClassPathXmlApplicationContext;

public class SpringLearn {
    public static void main(String[] args) {
        ApplicationContext context = new ClassPathXmlApplicationContext("Beans.xml");

        Learn1 learn1 = (Learn1) context.getBean("learn1");
        System.out.println(learn1.getNum1());
    }
}
