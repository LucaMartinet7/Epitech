"use client";

import { useEffect } from "react";
import { useParams } from "next/navigation";
import { useOrganizationList } from "@clerk/nextjs";

// OrgControl component
export const OrgControl = () => {
    const params = useParams(); // Get route parameters (e.g., organizationId) from the URL
    const { setActive } = useOrganizationList(); // Get the setActive function from Clerk's useOrganizationList hook

    useEffect(() => {
        if (!setActive) return;

        // Set the active organization using the organizationId from the route parameters
        setActive({ organization: params.organizationId as string });
    }, [setActive, params.organizationId]);

    return null;
};